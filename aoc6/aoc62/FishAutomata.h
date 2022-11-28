#pragma once
#include <vector>

class FishAutomata
{
public:
	std::vector<unsigned long long> initialState;
	std::vector<unsigned long long> getState();
	void alterState(std::vector<unsigned long long>& v);
	void setInitialState(std::vector<int>&);
};

