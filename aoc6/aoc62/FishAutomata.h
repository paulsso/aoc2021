#pragma once
#include <vector>

class FishAutomata
{
public:
	std::vector<unsigned long> initialState;
	std::vector<unsigned long> getState();
	void alterState(std::vector<unsigned long>& v);
	void setInitialState(std::vector<int>&);
};

