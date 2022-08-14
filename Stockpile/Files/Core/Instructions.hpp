#pragma once

/*
////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//		Contains list of instructions that can be used by the interpreter/compiler/debugger codes
//		will also house an instruction table 
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////
*/

enum e_instruction_item_types : quantum_t
{
	k_instruction_item_types_begin,


	_instruction_item_type_push,
	_instruction_item_type_pop,
	_instruction_item_type_add,
	_instruction_item_type_subtract,
	_instruction_item_type_multiply,
	_instruction_item_type_divide,
	_instruction_item_type_bitwise_or,
	_instruction_item_type_bitwise_and,
	_instruction_item_type_bitwise_xor,
	_instruction_item_type_bitwise_not,
	_instruction_item_type_bitwise_ror,
	_instruction_item_type_bitwise_rol,
	_instruction_item_type_bitwise_set,
	_instruction_item_type_bitwise_unset,
	_instruction_item_type_bitwise_flip,
	_instruction_item_type_nop,
	_instruction_item_type_break,
	_instruction_item_type_terminate,




	k_instruction_item_types_end,

};


constexpr auto MAX_INSTRUCTION_SET = 1 << (sizeof(quantum_t) * 8 - 1); //last bit will be reserved for system interrupts
