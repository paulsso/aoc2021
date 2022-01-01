#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <ctype.h>

typedef struct meta {
  bool marked;
  int number;
  int row;
  int col;
} meta;

typedef std::vector<std::vector<meta>> matrix;

long long VectorToInt(std::vector<int>);

void readInput(std::vector<int> &draw_numbers, matrix &boards,
  const std::string file_name);

void vectorizeStrToInt(std::vector<std::string> &input,
    std::vector<int> &output);

void vectorizeStrToInt(std::vector<std::string> &input,
    std::vector<int> &output)
{
    std::string str;
    std::vector<int> v;
    for ( auto c : input[0] ){
        if ( isdigit(c) ) { str+=c; }
        else { v.push_back(std::stoi(str)); str.clear(); }
    }
    output = v;
}

void readInput(std::vector<int> &draw_numbers, matrix &boards,
  const std::string file_name) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    std::fstream infile(file_name);
    int lineNo = 0;

    printf("Raw input: \n");

    while ( getline(infile,line) )
    {
        input1.push_back(line);
        std::cout << line << '\n' << std::endl;
        lineNo += 1;
        if (lineNo > 0) { break; }
    }
    while ( getline(infile,line) )
    {
        if (lineNo > 1) {
            input2.push_back(line);
            std::cout << line << std::endl;
        }
        lineNo += 1;
    }
    // get the first line, these are the bingo numbers, csv
    // the remaining numbers are all the bingo boards, put them in the matrix
    // use the meta struct to see check for bingo
    vectorizeStrToInt(input1, draw_numbers);

    printf("print drawn numbers: \n");
    for (auto n : draw_numbers) { printf("%d,",n); }

    infile.close();
}

int main()
{
    std::string file_name;
    std::vector<int> draw_numbers;
    matrix bingo_boards;
    std::cin >> file_name;

    readInput(draw_numbers, bingo_boards, file_name);
    return 0;
}
