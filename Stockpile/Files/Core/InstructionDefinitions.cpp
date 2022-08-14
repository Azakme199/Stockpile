#include "InstructionDefinitions.hpp"


//	class c_instruction_item_push
////////////////////////////////////////////////////////////////////////////////////////

e_instruction_item_types c_instruction_item_push::get_item_type() const
{
	return _instruction_item_type_push;
}
quantum_t c_instruction_item_push::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_push::get_item_operands_count() const
{
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////




//	class c_instruction_item_pop
////////////////////////////////////////////////////////////////////////////////////////

e_instruction_item_types c_instruction_item_pop::get_item_type() const
{
	return _instruction_item_type_pop;
}
quantum_t c_instruction_item_pop::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_pop::get_item_operands_count() const
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////



//	class c_instruction_item_add
////////////////////////////////////////////////////////////////////////////////////////

e_instruction_item_types c_instruction_item_add::get_item_type() const
{
	return _instruction_item_type_add;
}
quantum_t c_instruction_item_add::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_add::get_item_operands_count() const
{
	return 2;
}
////////////////////////////////////////////////////////////////////////////////////////
