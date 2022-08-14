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

constexpr auto MAX_VIRTUAL_CPU_REGISTERS = 4;
constexpr auto MAX_VIRTUAL_CPU_STACK_LENGTH = 8;
constexpr auto MAX_VIRTUAL_MEMORY_LENGTH = 8;
constexpr auto MIN_VIRTUAL_CPU_VSP = 0;

constexpr auto MAX_VIRTUAL_CPU_VSP = MAX_VIRTUAL_CPU_STACK_LENGTH - MIN_VIRTUAL_CPU_VSP - 1;


#define REGISTER_VAX 0
#define REGISTER_VBX 1
#define REGISTER_VCX 2
#define REGISTER_VDX 3


class c_virtual_cpu
{
	// processor needs a break?
	bool halted;

	// virtual instruction pointer
	quantum_t vip;

	// virtual stack pointer
	quantum_t vsp;

	// virtual data bus for connecting system resources
	quantum_t vbus;

	// virtual stack for processor
	quantum_t vstack[MAX_VIRTUAL_CPU_STACK_LENGTH];

	// virtual memory for processor
	quantum_t vmem[MAX_VIRTUAL_MEMORY_LENGTH];


	void cpu_internals_break();
	void cpu_internals_continue();

	bool cpu_internals_stack_full();
	bool cpu_internals_stack_empty();
	void cpu_internals_push_into_stack();
	void cpu_internals_pop_from_stack();
	void cpu_internals_clear_stack();


public:

	// general purpose registers for operations
	quantum_t vregs[MAX_VIRTUAL_CPU_REGISTERS];

	





	c_virtual_cpu();



	/*
		Does a memory fetch and push into stack
	*/
	bool cpu_execute_push();
	/*
		Push data bus into stack
	*/
	bool cpu_push_data();
	/*
		Overrides data bus and push into stack
	*/
	bool cpu_push_data(const quantum_t in);	
	/*
		Overrides data bus with top of stack
	*/
	bool cpu_pop_data();
	/*
		Fetches top of stack into out
	*/
	bool cpu_pop_data(quantum_t& out);


};
