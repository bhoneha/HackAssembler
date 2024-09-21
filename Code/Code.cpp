#include "Code.hpp"

std::string Code::dest(std::string dest)
{
	std::sort(dest.begin(), dest.end());
	if (!dest.empty()) {
		if (Code::pairs.dest.find(dest) == Code::pairs.dest.end()) {
			return "Instruction not found";
		}
		return Code::pairs.dest[dest];
	}
	return Code::pairs.dest[""];
}

std::string Code::comp(std::string comp)
{
	if (!comp.empty()) {
		if (comp.find("M") == std::string::npos) return Code::pairs.comp_A[comp];
		else return Code::pairs.comp_M[comp];
	}
	return "Instruction not found";
}

std::string Code::jump(std::string jump)
{
	if (!jump.empty()) {
		if (Code::pairs.jump.find(jump) == Code::pairs.jump.end()) {
			return "Instruction not found";
		}
		return Code::pairs.jump[jump];
	}
	return Code::pairs.jump[""];
}

std::string Code::A_const(std::string decimal)
{
	unsigned int dec = std::stoi(decimal);
	std::bitset<15> bs{ dec };

	return bs.to_string();
}

