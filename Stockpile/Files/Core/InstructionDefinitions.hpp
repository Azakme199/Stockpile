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
///////////////////////////
*/
class c_instruction_item_push :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};






/*
///////////////////////////
//
//	pop integer from stack
//	
///////////////////////////
*/
class c_instruction_item_pop :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};






/*
///////////////////////////
//
//	add two integers
//
///////////////////////////
*/
class c_instruction_item_add :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};






/*
///////////////////////////
//
//	subtract two integers
//
///////////////////////////
*/
class c_instruction_item_subtract :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};





/*
///////////////////////////
//
//	multiply two integers
//
///////////////////////////
*/
class c_instruction_item_multiply :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};






/*
///////////////////////////
//
//	divide two integers
//
///////////////////////////
*/
class c_instruction_item_divide :public c_instruction_item
{
public:
	// type of instruction
	e_instruction_item_types get_item_type() const override;


	//	size in bytes current instruction takes
	quantum_t get_item_size() const override;


	//	no of operands current instruction takes
	quantum_t get_item_operands_count() const override;
};
