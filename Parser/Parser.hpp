#pragma once

#include "../instruction_types.hpp"
#include <fstream>
#include <string>
#include <iostream>

class Parser {
private:
	std::ifstream file;
public:
	std::string curr_inst; // current instruction
	Parser(std::string filename); // open the filestream
	bool hasMoreLines(); // check if end of file has reached
	void advance(); // set curr_inst to next instruction
	inst_type instructionType();
	// C-instruction format : dest=comp;jmp
	std::string dest();
	std::string comp();
	std::string jump();

	std::string symbol();
};
