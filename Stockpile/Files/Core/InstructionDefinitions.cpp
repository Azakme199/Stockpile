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




//	class c_instruction_item_nop
////////////////////////////////////////////////////////////////////////////////////////

e_instruction_item_types c_instruction_item_nop::get_item_type() const
{
	return _instruction_item_type_nop;
}
quantum_t c_instruction_item_nop::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_nop::get_item_operands_count() const
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
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////



//	class c_instruction_item_subtract
////////////////////////////////////////////////////////////////////////////////////////
e_instruction_item_types c_instruction_item_subtract::get_item_type() const
{
	return _instruction_item_type_subtract;
}
quantum_t c_instruction_item_subtract::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_subtract::get_item_operands_count() const
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////



//	class c_instruction_item_multiply
////////////////////////////////////////////////////////////////////////////////////////
e_instruction_item_types c_instruction_item_multiply::get_item_type() const
{
	return _instruction_item_type_multiply;
}
quantum_t c_instruction_item_multiply::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_multiply::get_item_operands_count() const
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////



//	class c_instruction_item_divide
////////////////////////////////////////////////////////////////////////////////////////
e_instruction_item_types c_instruction_item_divide::get_item_type() const
{
	return _instruction_item_type_divide;
}
quantum_t c_instruction_item_divide::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_divide::get_item_operands_count() const
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////



//	class c_instruction_item_terminate
////////////////////////////////////////////////////////////////////////////////////////
e_instruction_item_types c_instruction_item_terminate::get_item_type() const
{
	return _instruction_item_type_terminate;
}
quantum_t c_instruction_item_terminate::get_item_size() const
{
	return sizeof(quantum_t) * get_item_operands_count() + sizeof(quantum_t);
}
quantum_t c_instruction_item_terminate::get_item_operands_count() const
{
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////


