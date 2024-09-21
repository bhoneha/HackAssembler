#include <iostream>
#include "Parser/Parser.hpp"
#include "Code/Code.hpp"
#include "translations.hpp"
#include "SymbolTable/SymbolTable.hpp"

int main() {
	std::ofstream file("out.hack");
	// parser to contruct symbol table
	Parser p("test.asm");
	// parser for translation
	Parser i("test.asm");

	Code c;
	translations t;
	SymbolTable table;

	unsigned int rom_addr = 0;
	unsigned int ram_addr = 16;

	while (p.hasMoreLines()) {
		p.advance();

		if (p.instructionType() == inst_type::LABEL) {
			std::string sym = p.symbol();
			if (!table.contains(sym)) {
				table.addEntry(sym, rom_addr);
			}
		}
		if (p.instructionType() == inst_type::A_INST || p.instructionType() == inst_type::C_INST) rom_addr++;
	}
	

	while (i.hasMoreLines()) {
		i.advance();
		
		if (i.instructionType() == inst_type::A_INST) {
			std::string sym = i.symbol();
			bool digit = false;
			for (char c : sym) {
				digit = std::isdigit(c);
				if (digit == false) {
					break;
				}
			}

			if (!digit) {
				if (!table.contains(sym)) {
					table.addEntry(sym, ram_addr);
					ram_addr++;
				}
			file << "0" << t.dec_to_bin(table.getAddress(sym)) << '\n';

			}
			else if(digit){
				file << "0" << t.dec_to_bin(sym) << '\n';
			}
		}

		if (i.instructionType() == inst_type::C_INST) {
			file << "111" << c.comp(i.comp()) << c.dest(i.dest()) << c.jump(i.jump()) << '\n';
		}
	}


	std::cout << table.getAddress("ponggame.0");
	return 0;
}