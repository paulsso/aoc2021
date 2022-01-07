#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <ctype.h>

void readInput(const std::string file_name, std::vector<int> &x_f, std::vector<int> &y_f,
        std::vector<int> &x_t, std::vector<int> &y_t);

void readInput(const std::string file_name, std::vector<int> &x_f, std::vector<int> &y_f,
        std::vector<int> &x_t, std::vector<int> &y_t) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::fstream infile(file_name);
    int charNo = 1;

    printf("Raw input: \n");

    while ( getline(infile,line) )
    {
        for (auto c : line) {
            if ( isdigit(c) ) {
                if ( 1 % charNo == 0 ) {
                    x_f.push_back(int(c) - 48); 
                }
                else if ( 2 % charNo == 0 ) {
                    y_f.push_back(int(c) - 48);
                }
                else if ( 3 % charNo == 0 ) {
                    x_t.push_back(int(c) - 48);
                }
                else if ( 4 % charNo == 0 ) {
                    y_t.push_back(int(c) - 48);
                }
            charNo += 1;
            }
        }
        charNo = 1;
        std::cout << line << std::endl;
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
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            u.push_back(0);
        }
        v.push_back(u);
    }

    for (int i=0; i < x_f.size(); i++) {
        v[x_f[i]][y_f[i]] += 1;
        v[x_t[i]][y_t[i]] += 1;
    }

    for (int i = 0; i < 10; i++) {
        u = v[i];
        for (int j = 0; j < 10; j++) {
            if ( u[j] != 0 ) {
                printf("%d",u[j]);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
