#include <iostream>
#include "Parser.hpp"

int main() {
    // testing
	Parser p("test.asm");
	while (p.hasMoreLines()) {
		p.advance();
		std::cout << p.curr_inst << " -> " << int(p.instructionType()) << '\n';
	}
	return 0;
}