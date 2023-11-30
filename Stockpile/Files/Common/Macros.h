#pragma once

// 8 bits cpu
typedef uint8_t quantum_t;

constexpr bool IN_RANGE(int option, int start, int end)
{
	return option > start && option < end;
}

constexpr quantum_t MAX(quantum_t left, quantum_t right)
{
	return left > right ? left : right;
}

constexpr quantum_t MIN(quantum_t left, quantum_t right)
{
	return left < right ? left : right;
}
