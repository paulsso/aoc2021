#pragma once
#include <string>
#include <vector>

class InputReader
{
private:
	void readInput();
public:
	std::vector<int> returnInput();
	std::vector<int> m_inputData;
};
