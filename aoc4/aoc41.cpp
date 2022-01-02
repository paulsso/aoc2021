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
    for ( auto line : input ) {
        for ( auto c : line ) {
            if ( isdigit(c) ) { str+=c; }
            else {
                if(!str.empty()) {
                    v.push_back(std::stoi(str)); str.clear(); } }
        }
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
    vectorizeStrToInt(input1, draw_numbers);

    while ( getline(infile,line) )
    {
        if (lineNo > 1) {
            input2.push_back(line + " ");
            std::cout << line << std::endl;
        }
        lineNo += 1;
    }
    
    std::vector<int> output;
    vectorizeStrToInt(input2, output);
    int i = 0;
    while (i<output.size()) {
        for (int j=0; j<5; j++) {
            std::vector<meta> board;
            for (int k=0; k<5; k++) {
                meta entry;
                entry.row = j;
                entry.col = k;
                entry.marked = false;
                entry.number = output[i];
                board.push_back(entry);
                i+=1;
            }
            boards.push_back(board);
        }
    }
    infile.close();
}

int main()
{
    std::string file_name;
    std::vector<int> draw_numbers;
    matrix bingo_boards;
    std::cin >> file_name;

    readInput(draw_numbers, bingo_boards, file_name);

    printf("Print drawn numbers: \n");
    for (auto n : draw_numbers) { printf("%d,", n); }

    return 0;
}
