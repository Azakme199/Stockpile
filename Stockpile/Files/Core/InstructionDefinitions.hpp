#pragma once
#include "Instructions.hpp"
#include "Common/Macros.h"

/*
////////////////////////////////////////////////////////////////////////////////////////
//
//
//	Contains actual instruction definitions
//
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////
*/

class c_instruction_item
{
	// type of instruction
	virtual e_instruction_item_types get_item_type() const = 0;
	//	size in bytes current instruction takes
	virtual quantum_t get_item_size() const = 0;
	//	no of operands current instruction takes
	virtual quantum_t get_item_operands_count() const = 0;
	//	routine that directly interacts with the cpu
	virtual quantum_t execute_item(quantum_t* args) = 0;
};
