#pragma once
#include <string>
#include <vector>

class InputHandler
{
private:
    void readInput(std::string filename);
public:
    std::vector<unsigned long int> returnInput(std::string filename);
    std::vector<unsigned long int> inputData;
    void processInput(std::vector<std::string>);
};
