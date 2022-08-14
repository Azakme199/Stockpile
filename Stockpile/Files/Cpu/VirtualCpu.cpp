#include "VirtualCpu.hpp"


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

	memset(this->vstack, 0, MAX_VIRTUAL_CPU_STACK_LENGTH * sizeof(quantum_t));
	memset(this->vregs, 0, MAX_VIRTUAL_CPU_REGISTERS *sizeof(quantum_t));
}

bool c_virtual_cpu::cpu_execute_push()
{
	this->vbus = this->vmem[this->vip + sizeof(quantum_t)]; //each instruction is of size quantum_t
	return this->cpu_push_data();
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

