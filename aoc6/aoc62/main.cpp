// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "InputHandler.h"
#include "FishAutomata.h"

int main() {

	InputHandler InputHandler;
	FishAutomata FishAutomata;
	auto input = InputHandler.returnInput("test.txt");

	FishAutomata.setInitialState(input);
	auto output = FishAutomata.getState();

	for (int i = 0; i < 257; i++) {
		FishAutomata.alterState(output);
		std::cout << "Day " << i << std::endl;
	}

	unsigned long sum = 0;
	for (int i = 0; i < output.size(); i++) {
		sum += output[i];
	}
	std::cout << "Answer: " << sum << std::endl;
	return 0;
}
