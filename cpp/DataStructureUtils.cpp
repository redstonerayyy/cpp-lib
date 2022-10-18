//
// Created by anton on 12/10/22.
//

#include "DataStructureUtils.hpp"

#include <iostream>

// find largest value in vector
int GetMaxRange(std::vector<int> &_vector, int start, int end){
    int max = _vector[0];
    for (int i = start; i < end; ++i) {
        if(_vector[i] > max){
            max = _vector[i];
        }
    }
    return max;
}

// find largest value in vector
int GetMax(std::vector<int> &_vector){
    int max = _vector[0];
    for (int i = 0; i < _vector.size(); ++i) {
        if(_vector[i] > max){
            max = i;
        }
    }
    return max;
}


// swap to elements, modifies the referenced vector
void SwapElements(std::vector<int> &_vector, int index1, int index2){
    // https://www.tutorialspoint.com/how-to-swap-two-arrays-without-using-temporary-variable-in-c-language
    // use in place swap trick without temporary variable
    _vector[index1] = _vector[index1] + _vector[index2];
    _vector[index2] = _vector[index1] - _vector[index2];
    _vector[index1] = _vector[index1] - _vector[index2];
}

// calculate prefixsum on a vector
void PrefixSum(std::vector<int> &_vector){
    for (int i = 1; i < _vector.size(); ++i) {
        _vector[i] = _vector[i - 1] + _vector[i];
    }
}

void PrintVector(std::vector<int> &_vector){
    for (int i : _vector) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}