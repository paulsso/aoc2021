// aoc71.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "InputHandler.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

const int find_max(std::vector<unsigned long int> v)
{
    unsigned long int max = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= max) {
            max = v[i];
        }
    }
    return max;
}

const int find_min(std::vector<unsigned long int> v)
{
    unsigned long int min = 4294967295;
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= min && v[i]>0) {
            min = v[i];
            index = i;
        }
    }
    return min;
}

int main()
{
    InputHandler inputHandler;
    auto data = inputHandler.returnInput("real_data.txt"); 
    auto max = find_max(data);
    std::vector<unsigned long int> posDict = {};
    std::vector<unsigned long int> costDict = {};

    for (int i = 0; i <= max; i++) {
        posDict.push_back(0);
        costDict.push_back(0);
    }
    unsigned long int j;
    for (int i = 0; i < data.size(); i++) {
        j = data[i];
        posDict[j] += 1;
    }

    for (int i = 0; i < costDict.size(); i++) {
        for (int j = 0; j < posDict.size(); j++) {
            costDict[i] += posDict[j] * std::abs(i - j);
        }
    }

    auto min = find_min(costDict);
    std::cout << min << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
