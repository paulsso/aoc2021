#include <fstream>
#include <iostream>
#include "InputHandler.h"

void tokenize(std::string const& str, const char delim,
	std::vector<std::string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void InputHandler::readInput(std::string filename) {
	std::string line;
	std::vector<std::string> lineOut;
	std::fstream infile(filename);
	const char del = ',';

	while (getline(infile, line)) {
		tokenize(line, del, lineOut);
	}
	infile.close();
	for (auto& s : lineOut)
		InputHandler::inputData.push_back(std::stoi(s));
	
}

std::vector<unsigned long int> InputHandler::returnInput(std::string filename) {
	InputHandler::readInput(filename);
	return InputHandler::inputData;
}

void InputHandler::processInput(std::vector<std::string>) {

}