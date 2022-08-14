#pragma once
#include "Instructions.hpp"

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
public:
	// type of instruction
	virtual e_instruction_item_types get_item_type() const = 0;


	//	size in bytes current instruction takes
	virtual quantum_t get_item_size() const = 0;


	//	no of operands current instruction takes
	virtual quantum_t get_item_operands_count() const = 0;
};




/*
///////////////////////////
//
//	push integer into stack
//
//
///////////////////////////
*/
class c_instruction_item_push :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const ;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};

