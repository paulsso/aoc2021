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

int computeBitCriteria(int, std::vector<std::string>&, std::string check); 

int computeRating(std::vector<std::string> &, std::string);

int computeBitCriteria(int position, std::vector<std::string> &input, std::string check)
{
    int counter = 0;
    int i;
    int il;
    
    for (const auto line : input) {
        i = 0;
        il = (int)(line[position]);
        if ( il == 48 ) {
            counter += 1; 
        }
        else if ( il == 49 ) { 
            counter -= 1; 
        }
        i+=1;
    }

    if (counter <= 0) {
        if (check == "o2") {
            return 1;
        }
        else if (check == "co2") {
            return 0;
        }
    }
    else
    {
        if (check == "o2") {
            return 0;
        }
        else if (check == "co2") {
            return 1;
        }
    }
}

void readInput(std::vector<std::string> &input, const std::string file_name) {

    std::cout << "Reading from file: " << file_name << std::endl;
    std::string line;
    std::fstream infile(file_name);

    while ( getline(infile,line) ) { 
        input.push_back(line);
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

int computeRating(std::vector<std::string> &input, std::string rating_type) 
{
    int bit_criteria;
    int index = 0;
    auto o2_vector = input; 
    int elems = o2_vector[0].size();
    
    std::cout<< "initial " << rating_type << " candidates: " << std::endl;
    for (const auto line : o2_vector) { std::cout << line << std::endl; }
    std::cout << std::endl;
    std::vector<std::string> to_be_removed;
    
    while (index < elems) {
        
        to_be_removed.clear();
        bit_criteria = computeBitCriteria(index, o2_vector, rating_type);
        
        for (const auto line : o2_vector) {
            auto it = std::find(o2_vector.begin(), o2_vector.end(), line);
            printf("Checking if %d matches bit criteria %d\n", 
                    (int)line[index], bit_criteria+48);
            if ( ((int)line[index] != (bit_criteria+48)) ) {
                std::cout << "To be removed is; " << line << std::endl;
                to_be_removed.push_back(line);
            }
        }

        for (auto line_2b_removed : to_be_removed) {
            if (o2_vector.size() == 1) { break; }
            auto it_remove = std::find(o2_vector.begin(), o2_vector.end(), line_2b_removed);
            if (it_remove != o2_vector.end()) { o2_vector.erase(it_remove); }
        }

        std::cout << "------" << std::endl;

        printf("iteration %d - remaining candidates: \n", index+1);
        for (const auto line : o2_vector) { std::cout << line << std::endl; }
        index += 1;
    }
   
    if (o2_vector.empty()) { 
        printf("bad, vector empty");
    }

    for (const auto line : o2_vector) { std::cout << 
        "final result (o2): " << line << std::endl; }
    std::cout << std::endl;

    std::vector<int> o2_int_vector; 
    for (auto line : o2_vector) {
        for (auto c : line) {
            o2_int_vector.push_back((int)c - 48);
        }
    }

    return convert( VectorToInt(o2_int_vector) );
}

int main()
{
    std::string file_name;
    std::vector<std::string> input;

    std::cin >> file_name;
    
    readInput(input, file_name);

    // use the binary rows to determine o2/co2 numbers
    // copy input to two new lists and then pop bad lines
    // the implementation below is missing a crucial part:
    // each time we remove an element, the bit criteria needs to be re-calculated
    // solution: abstract the first two steps of this algo into a fuction of its own
    // that returns the bit criteria 
 
    auto o2_vector = input;
    auto co2_vector = input;
    
    int o2_dec = computeRating(o2_vector,"o2");
    int co2_dec = computeRating(co2_vector,"co2");

    int life_support = o2_dec * co2_dec;
    printf("life support rating: %d\n", life_support);
    return 0;
}
