#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

void readInput(const std::string file_name, std::vector<int> &x_f, std::vector<int> &y_f,
        std::vector<int> &x_t, std::vector<int> &y_t);

void readInput(const std::string file_name, std::vector<int> &x_f, std::vector<int> &y_f,
        std::vector<int> &x_t, std::vector<int> &y_t) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::fstream infile(file_name);
    int charNo = 1;
    std::string put;
    printf("Raw input: \n");

    while ( getline(infile,line) )
    {
        line += '\n';
        for (auto c : line) {
            if ( (c == ',') 
                    || ( (c == ' ') && (charNo == 2) ) 
                        || ( c == '\n' ) ) {
                if ( charNo == 1 ) {
                    x_f.push_back(std::stoi(put)); 
                    charNo += 1;
                    put.clear();
                }
                else if ( charNo == 2 ) {
                    y_f.push_back(std::stoi(put));
                    charNo += 1;
                    put.clear();
                }
                else if ( charNo == 3 ) {
                    x_t.push_back(std::stoi(put));
                    charNo += 1;
                    put.clear();
                }
                else if ( charNo == 4 ) {
                    y_t.push_back(std::stoi(put));
                    charNo += 1;
                    put.clear();
                }
            } else if ( isdigit(c) ) {
                put += c;
            }
        }
        charNo = 1;
        // std::cout << line << std::endl;
    }
    infile.close();
}

int main () {

    std::string file_name;
    std::cin >> file_name;
    std::vector<int> x_f, y_f, x_t, y_t;

    readInput(file_name, x_f, y_f, x_t, y_t);

    printf("x_f\n");
    for ( auto i : x_f ) { printf("%d,", i); };
    printf("\n");

    printf("y_f\n");
    for ( auto i : y_f ) { printf("%d,", i); };
    printf("\n");
    
    printf("x_t\n");
    for ( auto i : x_t ) { printf("%d,", i); };
    printf("\n");
    
    printf("y_t\n");
    for ( auto i : y_t ) { printf("%d,", i); };
    printf("\n");

    std::vector<std::vector<int>> v;
    std::vector<int> u;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            u.push_back(0);
        }
        v.push_back(u);
    }

    for (int i=0; i < x_f.size(); ++i) 
    {
        if (y_f[i] == y_t[i]) 
        {
            if (x_f[i] < x_t[i]) {
                for (int n = x_f[i]; n <= x_t[i]; ++n) 
                {
                    v[y_f[i]][n] += 1;
                }
            } else {
                for (int n = x_t[i]; n <= x_f[i]; ++n) 
                {
                    v[y_t[i]][n] += 1;
                }
            }
        } 
        if (x_f[i] == x_t[i]) 
        {
            if (y_f[i] < y_t[i]) {
                for (int m = y_f[i]; m <= y_t[i]; ++m) 
                {
                    v[m][x_f[i]] += 1;
                }
            } else {
                for (int m = y_t[i]; m <= y_f[i]; ++m) 
                {
                    v[m][x_t[i]] += 1;
                }
            }
        }
    }
    long int target = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if ( v[i][j] != 0 ) {
                printf("%d",v[i][j]);
                if (v[i][j] >= 2) {
                    target += 1;
                }
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    printf("target: %d \n", target);

    return 0;
}
