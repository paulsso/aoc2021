#include "FishAutomata.h"
#include <algorithm>
#include <iostream>

void FishAutomata::setInitialState(std::vector<int>& v)
{
    // almost like a dictionary, but not quite. initialState[0] gives the nr of fish with internal timer = 0 etc.
    // this lets us "iterate" by simply shifting the vector to the left every day
    // and letting the number of state[8] for the next day be equal to state[0] of the previous day.
    FishAutomata::initialState = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < v.size(); i++) {
        FishAutomata::initialState.at(v[i]) += 1;
    }
}

std::vector<unsigned long> FishAutomata::getState()
{
    return FishAutomata::initialState;
}

void FishAutomata::alterState(std::vector<unsigned long>& v)
{
    unsigned long temp = v[0];
    for (int i = 0; i < v.size()-1; i++) {
        v[i] = v[i + 1];
    }
    v[6] += temp;
    v[8] = temp;
}
