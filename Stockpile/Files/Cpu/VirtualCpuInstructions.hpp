#pragma once
#include "Core/Instructions.hpp"
#include "Core/InstructionDefinitions.hpp"
#include "VirtualCpu.hpp"

/*
////////////////////////////////////////////////////////////////////////////////////////
//
//
//	Contains Virtual Processor Instruction Definitions
//
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////
*/

class c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	virtual bool execute(c_virtual_cpu* cpu) = 0;
};


class c_virtual_cpu_instruction_push : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_pop : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_nop : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_add : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_subtract : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_multiply : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};


class c_virtual_cpu_instruction_divide : public c_virtual_cpu_instruction
{

public:
	//	returns success or failure
	bool execute(c_virtual_cpu* cpu) override;
};
