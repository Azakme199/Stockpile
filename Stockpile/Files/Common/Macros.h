#pragma once



constexpr bool IN_RANGE(int option, int start, int end)
{
	return option > start && option < end;
}
