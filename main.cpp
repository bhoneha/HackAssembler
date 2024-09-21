#include <iostream>
#include "Parser/Parser.hpp"
#include "Code/Code.hpp"

int main() {
	std::ofstream file("out.hack");
	Parser p("test.asm");
	Code c;
	while (p.hasMoreLines()) {
		p.advance();
		if (p.instructionType() == inst_type::A_INST) {
			file << "0" << c.A_const(p.symbol()) << '\n';
		}
		else if (p.instructionType() == inst_type::C_INST) {
			file << "111" << c.comp(p.comp()) << c.dest(p.dest()) << c.jump(p.jump()) << '\n';
		}
		else {
			continue;
		}
	}

	// Debug code
	/*p.advance();
	std::cout << p.curr_inst << "  =>  " << int(p.instructionType()) << '\n';*/

	//std::cout << "Dest : " << p.dest() << '\n';
	//std::cout << "Comp : " << p.comp() << '\n';
	//std::cout << "Jump : " << p.jump() << '\n';
	//std::cout << "addr : " << p.symbol() << '\n';
	//// std::cout << "@" << c.A_const(p.symbol()) << '\n';
	//std::cout << "111" << " | " << c.comp(p.comp()) << " | " << c.dest(p.dest()) << " | " << c.jump(p.jump()) << '\n';
	
	return 0;
}