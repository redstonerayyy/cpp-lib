/*
This file contains various functions to print sequences of different types
like std::vector, std::array and C-like arrays.
It's functions should only be used with types which can be printed with
std::cout.
*/

#include "vector/print.hpp"

#include <cstdint>
#include <vector>
#include <array>
#include <iostream>

namespace Print {

// only 1 Dimension !
template <typename T>
T PrintOneDimensionalSequence(std::vector<T> &vector){
    for(std::uint64_t i = 0; i < vector.size(); ++i){
        std::cout << vector.at(i) << " ";
    }
    std::cout << "\n";
};

// only 1 Dimension !
template <typename T, std::uint64_t N>
T PrintOneDimensionalSequence(std::array<T, N> &stdarray){
    for(std::uint64_t i = 0; i < stdarray.size(); ++i){
        std::cout << stdarray.at(i) << " ";
    }
    std::cout << "\n";
};

// only 1 Dimension !
template <typename T>
T PrintOneDimensionalSequence(T array[], std::uint64_t size){
    for(std::uint64_t i = 0; i < size; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
};

}
