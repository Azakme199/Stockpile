#include "Cpu/VirtualCpu.hpp"
#include "Cpu/VirtualCpuInstructions.hpp"

void testPostFixEval()
{
	/*
	///////////////////////////
	//
	//	Perform 2+3
	//
	//	Infix to Postfix	: 2,3,+
	//	Bytecodes			:
	//		PSH 2
	//		PSH 3
	//		ADD
	//		EXT
	//
	///////////////////////////
	*/
	quantum_t arr[] = {
		_instruction_item_type_push,
		2,
		_instruction_item_type_push,
		3,
		_instruction_item_type_add,
		_instruction_item_type_terminate,
	};

	c_virtual_cpu myCpu;
	myCpu.cpu_memory_write(arr, sizeof(arr));
	myCpu.cpu_memory_run();
	myCpu.cpu_pop_data();
	DEBUG_SUCCESS("myCpu result (2+3) = {}", myCpu.cpu_memory_read_vbus());
}
