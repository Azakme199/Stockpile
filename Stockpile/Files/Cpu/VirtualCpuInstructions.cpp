#include "VirtualCpuInstructions.hpp"

bool c_virtual_cpu_instruction_push::execute(c_virtual_cpu* cpu)
{
	return cpu->cpu_execute_push();
}


bool c_virtual_cpu_instruction_pop::execute(c_virtual_cpu* cpu)
{
	return cpu->cpu_pop_data();
}


bool c_virtual_cpu_instruction_add::execute(c_virtual_cpu* cpu)
{
	if (cpu->cpu_pop_data(cpu->vregs[REGISTER_VAX])
		&& cpu->cpu_pop_data(cpu->vregs[REGISTER_VBX]))
	{
		//addition
		cpu->vregs[REGISTER_VAX] += cpu->vregs[REGISTER_VBX];		
		return cpu->cpu_push_data(cpu->vregs[REGISTER_VAX]);
	}
	return false;
}
