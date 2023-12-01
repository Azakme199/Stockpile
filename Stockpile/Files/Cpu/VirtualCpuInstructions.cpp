#include "VirtualCpuInstructions.hpp"

bool c_virtual_cpu_instruction_push::execute(c_virtual_cpu* cpu)
{

	//each instruction is of size quantum_t
	return cpu->cpu_push_data(cpu->cpu_memory_read_quantum(cpu->cpu_memory_read_vip() + sizeof(quantum_t)));
}


bool c_virtual_cpu_instruction_pop::execute(c_virtual_cpu* cpu)
{
	return cpu->cpu_pop_data();
}


bool c_virtual_cpu_instruction_nop::execute(c_virtual_cpu* cpu)
{
	return true;
}


bool c_virtual_cpu_instruction_add::execute(c_virtual_cpu* cpu)
{
	if (cpu->cpu_pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->cpu_pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//addition (bottom + top)
		cpu->vregs[REGISTER_VBX] += cpu->vregs[REGISTER_VAX];
		return cpu->cpu_push_data(cpu->vregs[REGISTER_VBX]);
	}
	return false;
}


bool c_virtual_cpu_instruction_subtract::execute(c_virtual_cpu* cpu)
{
	if (cpu->cpu_pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->cpu_pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//subtraction (bottom - top)
		cpu->vregs[REGISTER_VBX] -= cpu->vregs[REGISTER_VAX];
		return cpu->cpu_push_data(cpu->vregs[REGISTER_VBX]);
	}
	return false;
}


bool c_virtual_cpu_instruction_multiply::execute(c_virtual_cpu* cpu)
{
	if (cpu->cpu_pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->cpu_pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//multiply (bottom * top)
		cpu->vregs[REGISTER_VBX] *= cpu->vregs[REGISTER_VAX];
		return cpu->cpu_push_data(cpu->vregs[REGISTER_VBX]);
	}
	return false;
}


bool c_virtual_cpu_instruction_divide::execute(c_virtual_cpu* cpu)
{
	if (cpu->cpu_pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->cpu_pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//divide (bottom / top)
		cpu->vregs[REGISTER_VBX] /= cpu->vregs[REGISTER_VAX];
		return cpu->cpu_push_data(cpu->vregs[REGISTER_VBX]);
	}
	return false;
}
