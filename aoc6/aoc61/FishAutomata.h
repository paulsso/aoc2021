#pragma once
#include <vector>

class FishAutomata
{
private:
	int alterElement(int &n);
public:
	std::vector<int> initialState;
	std::vector<int> getState();
	void alterState();
	void setInitialState(std::vector<int>&);
};

