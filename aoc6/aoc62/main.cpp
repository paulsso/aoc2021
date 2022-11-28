// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "InputHandler.h"
#include "FishAutomata.h"

int main() {

	InputHandler InputHandler;
	FishAutomata FishAutomata;
	auto input = InputHandler.returnInput("test.txt");
	unsigned long long sum = 0;
	unsigned long long reproductiveFish;

	FishAutomata.setInitialState(input);
	auto output = FishAutomata.getState();

	for (int i = 0; i < 256; i++) {
		FishAutomata.alterState(output);
	}

	for (int i = 0; i < output.size(); i++) {
		sum += output[i];
	}

	std::cout << "The answer is: " << sum << std::endl;

	return 0;
}
