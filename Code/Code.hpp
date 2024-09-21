#pragma once

#include "../translations.hpp"
#include <string>
#include <algorithm>
#include <bitset>

class Code
{
private:
	translations pairs;
public:
	// translates mnemonics to binary
	std::string dest(std::string);
	std::string comp(std::string);
	std::string jump(std::string);

	std::string A_const(std::string); // translates the const of @xxx into binary
};

