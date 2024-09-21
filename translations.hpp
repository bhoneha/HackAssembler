#pragma once

#include <map>
#include <string>
#include <bitset>

struct translations {
	std::map <std::string, std::string> dest{
		{"","000"},
		{"M","001"},
		{"D","010"},
		{"DM","011"},
		{"A","100"},
		{"AM","101"},
		{"AD","110"},
		{"ADM","111"},
	};

	std::map <std::string, std::string> jump{
		{"","000"},
		{"JGT","001"},
		{"JEQ","010"},
		{"JGE","011"},
		{"JLT","100"},
		{"JNE","101"},
		{"JLE","110"},
		{"JMP","111"},
	};

	std::map <std::string, std::string> comp_A{
		{"0", "0101010"},
		{"1", "0111111"},
		{"-1", "0111010"},
		{"D", "0001100"},
		{"A", "0110000"},
		{"!D", "0001101"},
		{"!A", "0110001"},
		{"-D", "0001111"},
		{"-A", "0110011"},
		{"D+1", "0011111"},
		{"A+1", "0110111"},
		{"D-1", "0001110"},
		{"A-1", "0110010"},
		{"D+A", "0000010"},
		{"D-A", "0010011"},
		{"A-D", "0000111"},
		{"D&A", "0000000"},
		{"D|A", "0010101"},
	};

	std::map <std::string, std::string> comp_M{
		{"M","1110000"},
		{"!M","1110001"},
		{"-M","1110011"},
		{"M+1","1110111"},
		{"M-1","1110010"},
		{"D+M", "1000010"},
		{"D-M", "1010011"},
		{"M-D", "1000111"},
		{"D&M", "1000000"},
		{"D|M", "1010101"},
	};

	std::string dec_to_bin(std::string decimal)
	{
		unsigned int dec = unsigned int(std::stoi(decimal));
		std::bitset<15> bs{ dec };

		return bs.to_string();
	}

	std::string dec_to_bin(unsigned int decimal) {
		std::bitset<15> bs{ decimal };
		return bs.to_string();
	}
};
