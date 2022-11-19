#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "InputReader.h"

void InputReader::readInput() {
	std::string line;
	std::fstream infile("test.txt");

	while (getline(infile, line)) {
		InputReader::m_inputData.push_back(std::stoi(line));
	}
	infile.close();
}

std::vector<int> InputReader::returnInput() {
	InputReader::readInput();
	return InputReader::m_inputData;
}