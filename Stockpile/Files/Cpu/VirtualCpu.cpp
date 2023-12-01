#include <unordered_map>
#include "VirtualCpu.hpp"
#include "VirtualCpuInstructions.hpp"


/*
	Private Methods

*/


void c_virtual_cpu::cpu_internals_break()
{
	this->halted = true;
}

void c_virtual_cpu::cpu_internals_continue()
{
	this->halted = false;
}

bool c_virtual_cpu::cpu_internals_stack_full()
{
	return this->vsp == MAX_VIRTUAL_CPU_VSP;
}

bool c_virtual_cpu::cpu_internals_stack_empty()
{
	return this->vsp == MIN_VIRTUAL_CPU_VSP;
}

void c_virtual_cpu::cpu_internals_push_into_stack()
{
	this->vstack[++this->vsp] = this->vbus;
}

void c_virtual_cpu::cpu_internals_pop_from_stack()
{
	this->vbus = this->vstack[this->vsp--];
}

void c_virtual_cpu::cpu_internals_peek_stack()
{
	this->vbus = this->vstack[this->vsp];
}

void c_virtual_cpu::cpu_internals_peek_stack(size_t at)
{
	this->vbus = this->vstack[at];
}

c_instruction_item* cpu_instruction_fetch(e_instruction_item_types type)
{
	static c_instruction_item_push psh;
	static c_instruction_item_pop pop;
	static c_instruction_item_add add;
	static c_instruction_item_subtract sub;
	static c_instruction_item_multiply mul;
	static c_instruction_item_divide div;
	static c_instruction_item_nop nop;
	static c_instruction_item_terminate ext;

	std::unordered_map<quantum_t, c_instruction_item*> mapp =
	{
		{_instruction_item_type_push, &psh},
		{_instruction_item_type_pop, &pop},
		{_instruction_item_type_add, &add},
		{_instruction_item_type_subtract, &sub},
		{_instruction_item_type_multiply, &mul},
		{_instruction_item_type_divide, &div},
		{_instruction_item_type_nop, &nop},
		{_instruction_item_type_terminate, &ext},
	};
	if (mapp.find(type) != mapp.end())
		return mapp[type];

	return &nop;
}

c_virtual_cpu_instruction* cpu_instruction_decode(e_instruction_item_types type)
{
	static c_virtual_cpu_instruction_push psh;
	static c_virtual_cpu_instruction_pop pop;
	static c_virtual_cpu_instruction_add add;
	static c_virtual_cpu_instruction_subtract sub;
	static c_virtual_cpu_instruction_multiply mul;
	static c_virtual_cpu_instruction_divide div;
	static c_virtual_cpu_instruction_nop nop;
	static c_virtual_cpu_instruction_terminate ext;

	std::unordered_map<quantum_t, c_virtual_cpu_instruction*> mapp =
	{
		{_instruction_item_type_push, &psh},
		{_instruction_item_type_pop, &pop},
		{_instruction_item_type_add, &add},
		{_instruction_item_type_subtract, &sub},
		{_instruction_item_type_multiply, &mul},
		{_instruction_item_type_divide, &div},
		{_instruction_item_type_nop, &nop},
		{_instruction_item_type_terminate, &ext},
	};
	if (mapp.find(type) != mapp.end())
		return mapp[type];

	return &nop;
}

void c_virtual_cpu::cpu_internals_clear_stack()
{
	//	if we actually implement a base pointer approach
	//	then this->vsp = this->vbp

	this->vsp = MIN_VIRTUAL_CPU_VSP;
}


/*
	Public Methods

*/

c_virtual_cpu::c_virtual_cpu()
{
	this->halted = false;
	this->vip = 0;
	this->vsp = MIN_VIRTUAL_CPU_VSP;
	this->vbus = 0;

	//	tbh it doesnt matter even if zero them or not
	//	since we are never doing any arbitrary read/write

	memset(&this->vstack, 0, MAX_VIRTUAL_CPU_STACK_SIZE);
	memset(&this->vmem, 0, MAX_VIRTUAL_MEMORY_SIZE);
}


bool c_virtual_cpu::cpu_push_data()
{
	if (this->cpu_internals_stack_full())
	{
		DEBUG_ERROR_FXN("stack is full! failed to push data_bus");
		return false;
	}

	this->cpu_internals_push_into_stack();
	return true;
}

bool c_virtual_cpu::cpu_push_data(const quantum_t in)
{
	this->vbus = in;
	return this->cpu_push_data();

}

bool c_virtual_cpu::cpu_pop_data()
{
	if (this->cpu_internals_stack_empty())
	{
		DEBUG_ERROR_FXN("stack is empty! failed to retreive from stack");
		return false;
	}

	this->cpu_internals_pop_from_stack();
	return true;
}

bool c_virtual_cpu::cpu_pop_data(quantum_t& out)
{
	if (!this->cpu_pop_data())
		return false;

	out = this->vbus;
	return true;
}

void c_virtual_cpu::cpu_memory_write(quantum_t* memory, const size_t sz)
{
	if (sz > MAX_VIRTUAL_MEMORY_SIZE)
	{
		memcpy(this->vmem, memory, MAX_VIRTUAL_MEMORY_SIZE);
		DEBUG_WARNING_FXN("write size exceeded MAX_VIRTUAL_MEMORY_SIZE ..partially written");
		return;
	}
	memcpy(this->vmem, memory, sz);
}

void c_virtual_cpu::cpu_memory_write_quantum(const size_t at, const quantum_t in)
{
	if (!IN_RANGE(at, -1, MAX_VIRTUAL_MEMORY_LENGTH))
	{
		DEBUG_WARNING_FXN("out of range detected ..skipping");
		return;
	}

	this->vmem[at] = in;

}

void c_virtual_cpu::cpu_memory_write_block(quantum_t* memory, const size_t at, const  size_t sz)
{
	if(!IN_RANGE(at, -1, MAX_VIRTUAL_MEMORY_LENGTH))
	{
		DEBUG_WARNING_FXN("out of range detected ..skipping");
		return;
	}
	if (at + sz > MAX_VIRTUAL_MEMORY_SIZE)
	{
		memcpy(this->vmem + at, memory, MAX_VIRTUAL_MEMORY_SIZE-at);
		DEBUG_WARNING_FXN("write size exceeded MAX_VIRTUAL_MEMORY_SIZE ..partially written");
		return;
	}
	memcpy(this->vmem + at, memory, sz);
}

const quantum_t* c_virtual_cpu::cpu_memory_read()
{
	return static_cast<const quantum_t*>(this->vmem);
}

const quantum_t c_virtual_cpu::cpu_memory_read_quantum(const size_t at)
{
	if (IN_RANGE(at, -1, MAX_VIRTUAL_MEMORY_LENGTH))
		return static_cast<const quantum_t>(this->vmem[at]);

	DEBUG_WARNING_FXN("out of range detected");
	return static_cast<const quantum_t>(quantum_t());
}

const quantum_t c_virtual_cpu::cpu_memory_read_vip()
{
	return static_cast<const quantum_t>(this->vip);
}

const quantum_t c_virtual_cpu::cpu_memory_read_vsp()
{
	return static_cast<const quantum_t>(this->vsp);
}

const quantum_t c_virtual_cpu::cpu_memory_read_vbus()
{
	return static_cast<const quantum_t>(this->vbus);
}

void c_virtual_cpu::cpu_memory_write_vbus(const quantum_t in)
{
	this->vbus = in;
}

void c_virtual_cpu::cpu_memory_stop()
{
	DEBUG_ERROR_FXN("stopping execution..");
	this->cpu_internals_break();
}

void c_virtual_cpu::cpu_memory_run()
{
	this->cpu_internals_continue();
	while(!this->halted)
	{
		quantum_t byte_code = this->cpu_memory_read_quantum(this->vip);
		e_instruction_item_types insn = static_cast<e_instruction_item_types>(byte_code);
		c_virtual_cpu_instruction* decoded_insn = cpu_instruction_decode(insn);
		c_instruction_item* insn_definition = cpu_instruction_fetch(insn);
		
		// run the instruction
		decoded_insn->execute(this);
		// move the program ahead
		this->vip += insn_definition->get_item_size();
	}
}

