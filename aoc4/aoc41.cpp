#include <iostream>
#include <vector>
#include <string>


void readInput(std::vector<std::string> &input, const std::string file_name);

void readInput(std::vector<std::string> &input, const std::string file_name) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::fstream infile(file_name);

    while ( getline(infile,line) ) { 
        input.push_back(line);
    }

    infile.close();
}

int main() 
{
    std::string file_name;
    std::vector<std::string> input;

    std::cin >> file_name;
    
    readInput(input, file_name);
    
    return 0;
}

