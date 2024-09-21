#pragma once

#include "../translations.hpp"
#include <string>
#include <algorithm>

class Code
{
private:
	translations pairs;
public:
	// translates mnemonics to binary
	std::string dest(std::string);
	std::string comp(std::string);
	std::string jump(std::string);
};

