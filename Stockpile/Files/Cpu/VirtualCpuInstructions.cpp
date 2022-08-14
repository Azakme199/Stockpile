#include "VirtualCpuInstructions.hpp"

bool c_virtual_cpu_instruction_push::execute(c_virtual_cpu* cpu)
{
	return cpu->push_data_internal();
}


bool c_virtual_cpu_instruction_pop::execute(c_virtual_cpu* cpu)
{
	return cpu->pop_data_internal();
}


bool c_virtual_cpu_instruction_add::execute(c_virtual_cpu* cpu)
{
	if (cpu->pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//addition
		cpu->vregs[REGISTER_VAX] += cpu->vregs[REGISTER_VBX];		
		return cpu->push_data(cpu->vregs[REGISTER_VAX]);
	}
	return false;
}
