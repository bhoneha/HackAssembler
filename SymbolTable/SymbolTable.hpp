#pragma once

#include <unordered_map>
#include <string>

class SymbolTable {
private:
	std::unordered_map<std::string,unsigned int> table;
public:
	SymbolTable();

	void addEntry(std::string symbol, unsigned int address);
	bool contains(std::string symbol);
	unsigned int getAddress(std::string symbol);

};