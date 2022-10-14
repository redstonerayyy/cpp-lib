//
// Created by anton on 12/10/22.
//

#ifndef CPP_ALGOS_DATASTRUCTUREUTILS_HPP
#define CPP_ALGOS_DATASTRUCTUREUTILS_HPP

#include <vector>
#include <iostream>

int GetMax(std::vector<int> &_vector);
void SwapElements(std::vector<int> &_vector, int index1, int index2);
void PrefixSum(std::vector<int> &_vector);
template <typename T>
void PrintIterator(std::vector<T> &_vector){
    for (T i: _vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

#endif //CPP_ALGOS_DATASTRUCTUREUTILS_HPP
