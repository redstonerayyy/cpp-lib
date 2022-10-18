#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#include "RadixSortMultithreaded.hpp"

int main() {
    auto genstart = std::chrono::high_resolution_clock::now();

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 100000000); // define the range

    std::vector<int> test;

    for(int i = 0; i < 100000000; ++i){
        test.push_back(distr(gen));
    }

    auto genstop = std::chrono::high_resolution_clock::now();

    auto genduration = std::chrono::duration_cast<std::chrono::microseconds>(genstop - genstart);
    std::cout << float(genduration.count())/1000000 << std::endl;

    auto sortstart = std::chrono::high_resolution_clock::now();

    RadixSortMultithreaded(test);

    auto sortstop = std::chrono::high_resolution_clock::now();

    auto sortduration = std::chrono::duration_cast<std::chrono::microseconds>(sortstop - sortstart);
    std::cout << float(sortduration.count())/1000000 << std::endl;
    return 0;
}
