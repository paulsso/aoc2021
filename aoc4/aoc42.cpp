#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <ctype.h>
#include <math.h>

typedef struct meta {
    int drawn;
    int number;
    int row;
    int col;
} meta;
typedef std::vector<meta> matrix;
typedef std::vector<matrix> matrices;

long long VectorToInt(std::vector<int>);

bool checkAllTrue(std::vector<int> v);

bool checkIfBingo(matrix &board, int index, int has_won);

void indecesOfColumns(const int row, const int col, std::vector<int> &);

void indecesOfRows(const int row, std::vector<int> &);

void readInput(std::vector<int> &draw_numbers, matrices &boards,
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
        if(!str.empty()) {
            v.push_back(std::stoi(str)); str.clear();
        }
    }
    output = v;
}

void readInput(std::vector<int> &draw_numbers, matrices &boards,
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
            input2.push_back(line);
            std::cout << line << std::endl;
        }
        lineNo += 1;
    }

    std::vector<int> output;
    vectorizeStrToInt(input2, output);
    int i = 0;
    while (i<output.size()) {
        std::vector<meta> board;
        for (int j=0; j<5; j++) {
            for (int k=0; k<5; k++) {
                meta entry;
                entry.row = j;
                entry.col = k;
                entry.drawn = false;
                entry.number = output[i];
                board.push_back(entry);
                i+=1;
            }
        }
        boards.push_back(board);
    }
    infile.close();
}

void indecesOfColumns(const int row, const int col, std::vector<int> &indeces) {
    static int index;
    int i = 0;
    while(i<5) {
        index = i*5 + col;
        indeces.push_back( index );
        i+=1;
    }
}

void indecesOfRows(const int row, std::vector<int> &indeces) {
    int index;
    int i = 0;
    while(i<5) {
        index = row*5 + i;
        indeces.push_back( index );
        i+=1;
    }
}

bool checkAllTrue(std::vector<int> v) {
    for (int val : v) {
        if(val == 0)
        {
            return false;
        }
    }
    return true;
}

bool checkIfBingo(matrix &board, int index, int has_won) {
    int target;
    std::vector<int> columns;
    std::vector<int> rows;
    std::vector<int> bingo_cols;
    std::vector<int> bingo_rows;

    indecesOfColumns(board[index].row, board[index].col, columns);
    for (auto i : columns) { bingo_cols.push_back(board[i].drawn); }

    indecesOfRows(board[index].row, rows);
    for (auto i : rows) { bingo_rows.push_back(board[i].drawn); }

    if(checkAllTrue(bingo_cols)) {
        if (has_won == 0) {
            int sum = 0;
            printf("winning col: \n");
            for (int i=0; i<25; i++) {
                printf("%d ", board[i].number);
                if (board[i].drawn == 0) {
                    sum += board[i].number;
                }
            }
            target = sum*board[index].number;
            printf("target: %d \n", target);
            return true;
        }
    }

    if(checkAllTrue(bingo_rows)) {
        if (has_won == 0) {
            int sum = 0;
            printf("winning row: \n");
            for (int i=0; i<25; i++) {
                printf("%d ", board[i].number);
                if (board[i].drawn == 0) {
                    sum += board[i].number;
                }
            }
            printf("\n%d * %d = ", sum, board[index].number);
            target = sum*board[index].number;
            printf("%d \n", target);
            return true;
        }
    }

    return false;
}

int main()
{
    std::vector<int> has_won;
    std::string file_name;
    std::vector<int> draw_numbers;
    matrices bingo_boards;
    std::cin >> file_name;

    readInput(draw_numbers, bingo_boards, file_name);
    
    for (int i; i<bingo_boards.size(); i++) {
        has_won.push_back(0);
    }

    for (auto n : draw_numbers) {
        for (int m=0; m<bingo_boards.size(); m++) {
            for (int i=0; i<25; i++) {
                if (n == bingo_boards[m][i].number) {
                    bingo_boards[m][i].drawn = 1;
                    if (checkIfBingo(bingo_boards[m], i, has_won[m])) {
                        if (has_won[m] == 0) {
                            has_won[m] = 1;
                            printf("bingo\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
