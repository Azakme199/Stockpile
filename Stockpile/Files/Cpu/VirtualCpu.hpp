#pragma once

/*
////////////////////////////////////////////////////////////////////////////////////////
//
//
//	Contains Virtual Processor definitions
//
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////
*/


constexpr auto MAX_VIRTUAL_CPU_STACK_SIZE = 8;
constexpr auto MAX_VIRTUAL_CPU_REGISTERS = 4;

class c_virtual_cpu
{
	// processor needs a break?
	bool halted;

	// virtual instruction pointer
	quantum_t vip;

	// virtual stack pointer
	quantum_t vsp;

	// general purpose registers for operations
	quantum_t  vregs[MAX_VIRTUAL_CPU_REGISTERS];

	// virtual stack for processor
	quantum_t vstack[MAX_VIRTUAL_CPU_STACK_SIZE];


	void cpu_break();
	void cpu_continue();

	void cpu_push_item(quantum_t);
	quantum_t cpu_pop_item();

public:

	
};
