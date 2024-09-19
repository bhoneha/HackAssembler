#pragma once

#include "instruction_types.hpp"
#include <fstream>
#include <string>
#include <iostream>

class Parser {
private:
	std::ifstream file;
public:
	// current instruction
	std::string curr_inst;
	// open the filestream
	Parser(std::string filename);

	// check if end of file has reached
	bool hasMoreLines();
	// set curr_inst to next instruction
	void advance();

	inst_type instructionType();
	std::string symbol();
};