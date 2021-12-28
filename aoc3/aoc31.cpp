#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>

int convert(long long);

long long VectorToInt(std::vector<int>);

void readInput(std::vector<std::string> &input, const std::string file_name);

void readInput(std::vector<std::string> &input, const std::string file_name) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::fstream infile(file_name);

    while ( getline(infile,line) ) { 
        input.push_back(line);
        //std::cout << line << std::endl; 
    }

    infile.close();
}

// function definition
int convert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
    rem = n % 10;
    n /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}

// function to convert vector of integers to a single number
long long VectorToInt(std::vector<int> v)
{
    std::reverse(v.begin(), v.end());
    long long decimal = 1;
    long long total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}

int main()
{
    std::string file_name;
    std::vector<std::string> input;
    std::vector<int> counter = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::cin >> file_name;
    std::vector<int> gamma_binary;
    std::vector<int> epsilon_binary;
    
    readInput(input, file_name);
    
    int i;
    int il;
    int gamma_rate;
    int epsilon_rate;
    int fuel;

    for (const std::string line : input) {
        i = 0;
        for (const char c : line) { 
            il = (int)(c);
           // std::cout << il;
            if ( c == 0 ) {
                counter[i] += 1; 
            }
            else if ( c == 1 ) { 
                counter[i] -= 1; 
            }
            i+=1;
        }       
    }

    int j = 0;
    for (const int i : counter) {
        if (i < 0) {
            gamma_binary.push_back(1);
            epsilon_binary.push_back(0);
        }
        else
        {
            gamma_binary.push_back(0);
            epsilon_binary.push_back(1);
        }
    }

    printf("gamma binary: %d,%d,%d,%d,%d \n", gamma_binary[0], gamma_binary[1], gamma_binary[2], gamma_binary[3],
            gamma_binary[4]);

    printf("epsilon binary: %d,%d,%d,%d,%d \n", epsilon_binary[0], epsilon_binary[1], epsilon_binary[2],
            epsilon_binary[3], epsilon_binary[4]);

    gamma_rate = convert( VectorToInt( gamma_binary ) );
    epsilon_rate = convert( VectorToInt( epsilon_binary ) );
    fuel = gamma_rate * epsilon_rate;

    printf("The fuel consumtion is: %d \n", fuel);

    return 0;
}
