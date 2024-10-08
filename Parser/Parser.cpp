#include "Parser.hpp"

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
	bool valid_inst = false;
	while (!valid_inst && std::getline(Parser::file, Parser::curr_inst)) {
		// remove whitespaces
		for (size_t i{}; i < Parser::curr_inst.size(); i++) {
			if (Parser::curr_inst[i] == ' ') {
				Parser::curr_inst.erase(i, 1);
				// adjusting index for new string content
				i--;
			}
		}

		if (Parser::instructionType() != inst_type::NONE && Parser::instructionType() != inst_type::COMMENT) valid_inst = true;
	}
}

// return A_INST or C_INST or NONE or COMMENT
inst_type Parser::instructionType()
{
	if (!Parser::curr_inst.empty()) {
		if (Parser::curr_inst.substr(0, 2) == "//") return inst_type::COMMENT;
		else if (Parser::curr_inst.find('(') != Parser::curr_inst.npos) return inst_type::LABEL;
		else if (Parser::curr_inst[0] == '@') return inst_type::A_INST;
		return inst_type::C_INST;
	}
	return inst_type::NONE;
}

std::string Parser::dest()
{
	int index_of_equal = Parser::curr_inst.find('=');
	// one character before '='
	return index_of_equal == std::string::npos ? std::string{} : Parser::curr_inst.substr(0, index_of_equal);
}

std::string Parser::comp()
{
	int index_of_equal = Parser::curr_inst.find('=');
	int index_of_semicolon = Parser::curr_inst.find(';');
	if (index_of_semicolon == std::string::npos)
		return Parser::curr_inst.substr(index_of_equal + 1, -1);
	return Parser::curr_inst.substr(index_of_equal + 1, index_of_semicolon - (index_of_equal + 1));
}

std::string Parser::jump()
{
	int index_of_semicolon = Parser::curr_inst.find(';');
	// 3 characters after ';'
	return index_of_semicolon == std::string::npos ? std::string{} : Parser::curr_inst.substr(index_of_semicolon + 1, 3);
}

std::string Parser::symbol()
{
	if (Parser::instructionType() == inst_type::A_INST) {
		int index_of_at = Parser::curr_inst.find('@');
		return Parser::curr_inst.substr(index_of_at + 1, -1);
	}
	else if (Parser::instructionType() == inst_type::LABEL) {
		int index_start = Parser::curr_inst.find("(") + 1;
		int size = Parser::curr_inst.find(")") - index_start;

		return Parser::curr_inst.substr(index_start, size);
	}
	return std::string{};
}

