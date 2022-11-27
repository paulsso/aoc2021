#pragma once
#include <string>
#include <vector>

class InputHandler
{
private:
    void readInput(std::string filename);
public:
    std::vector<int> returnInput(std::string filename);
    std::vector<int> inputData;
    void processInput(std::vector<std::string>);
};
