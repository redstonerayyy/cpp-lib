#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "RadixSort.hpp"

int main() {
    auto genstart = std::chrono::high_resolution_clock::now();

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 100); // define the range

    std::vector<int> test;

    for(int i = 0; i < 100000000; ++i){
        test.push_back(distr(gen));
    }

    auto genstop = std::chrono::high_resolution_clock::now();

    auto genduration = std::chrono::duration_cast<std::chrono::microseconds>(genstop - genstart);
    std::cout << float(genduration.count())/1000000 << std::endl;

    auto sortstart = std::chrono::high_resolution_clock::now();
    
    RadixSort(test);
//     for (int i : test) {
//         std::cout << i << std::endl;
//     }

    auto sortstop = std::chrono::high_resolution_clock::now();

    auto sortduration = std::chrono::duration_cast<std::chrono::microseconds>(sortstop - sortstart);
    std::cout << float(sortduration.count())/1000000 << std::endl;
    return 0;
}
