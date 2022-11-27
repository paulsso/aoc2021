#include <fstream>
#include "InputHandler.h"

void InputHandler::readInput(std::string filename) {
	std::string line;
	std::fstream infile(filename);
	int j;

	while (getline(infile, line)) {
		for (int i = 0; i < line.size(); i+=2) {
			j = line[i];
			InputHandler::inputData.push_back(j-48);
		}
	}
	infile.close();
}

std::vector<int> InputHandler::returnInput(std::string filename) {
	InputHandler::readInput(filename);
	return InputHandler::inputData;
}

void InputHandler::processInput(std::vector<std::string>) {

}