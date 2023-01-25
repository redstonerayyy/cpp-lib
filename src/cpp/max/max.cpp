/*
This file contains useful functions to find maximum values in vector and arrays
of different types. It's functions should only be used with numeric values 
(int, double, ...) because it uses the standard comparison operator '>' .
*/

#include "max/max.hpp"

#include <cstdint>
#include <vector>
#include <array>

namespace Max {

template <typename T>
T GetMax(std::vector<T> &vector){
    T max = vector.at(0);
    for(std::uint64_t i = 0; i < vector.size(); ++i){
        if(vector.at(i) > max){
            max = vector.at(i);
        }
    }
    return max;
};

template short Max::GetMax<short>(std::vector<short> &vector);
template int Max::GetMax<int>(std::vector<int> &vector);
template long Max::GetMax<long>(std::vector<long> &vector);
template float Max::GetMax<float>(std::vector<float> &vector);
template double Max::GetMax<double>(std::vector<double> &vector);

template <typename T>
T GetMaxInRange(std::vector<T> &vector, std::uint64_t start, std::uint64_t end){
    T max = vector.at(0);
    std::uint64_t upperbound = end + 1 > vector.size() ? vector.size() : end + 1;
    for(std::uint64_t i = start; i < upperbound; ++i){
        if(vector.at(i) > max){
            max = vector.at(i);
        }
    }
};

template short GetMaxInRange<short>(std::vector<short> &vector, std::uint64_t start, std::uint64_t end);
template int GetMaxInRange<int>(std::vector<int> &vector, std::uint64_t start, std::uint64_t end);
template long GetMaxInRange<long>(std::vector<long> &vector, std::uint64_t start, std::uint64_t end);
template float GetMaxInRange<float>(std::vector<float> &vector, std::uint64_t start, std::uint64_t end);
template double GetMaxInRange<double>(std::vector<double> &vector, std::uint64_t start, std::uint64_t end);

}
