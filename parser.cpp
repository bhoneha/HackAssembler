#include "parser.hpp"

Parser::Parser(std::string filename)
{
	Parser::file.open(filename);
	
	if (Parser::file.fail()) {
		std::cerr << "Failed to open the file" << '\n';
		exit(EXIT_FAILURE);
	}
}

bool Parser::hasMoreLines()
{
	if (Parser::file.eof()) {
		return false;
	}
	return true;
}

// set the current instruction (curr_inst) to the next instruction
// if the next is not A_INST nor C_INST, get the next instruction again
void Parser::advance()
{
	bool valid_inst = true;
	while (std::getline(Parser::file, Parser::curr_inst) && !valid_inst) {
		if (Parser::instructionType() == inst_type::NONE) valid_inst = false;
	}
}

// return A_INST or C_INST or NONE
inst_type Parser::instructionType()
{
	if (!Parser::curr_inst.empty()) {
		if (Parser::curr_inst[0] == '@') return inst_type::A_INST;
		return inst_type::C_INST;
	}
	return inst_type::NONE;
}

std::string Parser::symbol()
{
	return std::string();
}
