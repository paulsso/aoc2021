#include "FishAutomata.h"

void FishAutomata::setInitialState(std::vector<int>& v)
{
    FishAutomata::initialState = v;
}

std::vector<int> FishAutomata::getState()
{
    return FishAutomata::initialState;
}

void FishAutomata::alterState()
{
    int j = 0;
    for (int i = 0; i < FishAutomata::initialState.size(); i++) {
        j += alterElement(FishAutomata::initialState[i]);
    }

    for (int k = 0; k < j; k++) {
        FishAutomata::initialState.push_back(8);
    }
}

int FishAutomata::alterElement(int &n)
{
    int j = 0;
    if (n == 0) {
        n = 6;
        j += 1;
    }
    else {
        n -= 1;
    }
    return j;
}
