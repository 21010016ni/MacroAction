#pragma once
#include <fstream>

class BinIO
{
public:
	std::fstream fst;

	BinIO(const char* s, std::ios_base::openmode mode) :fst(s, mode | std::ios::binary)
	{

	}
};

