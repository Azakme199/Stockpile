#pragma once

// 8 bits cpu
typedef uint8_t quantum_t;

constexpr bool IN_RANGE(int option, int start, int end)
{
	return option > start && option < end;
}
