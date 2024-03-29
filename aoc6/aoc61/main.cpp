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
	for (int i = 0; i < 81; i++) {
		FishAutomata.alterState();
	}
	auto output = FishAutomata.getState();

	std::cout << "The answer is " << output.size() << std::endl;

	return 0;
}
