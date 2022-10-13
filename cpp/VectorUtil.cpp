//
// Created by anton on 12/10/22.
//

#include "VectorUtil.hpp"

void SwapElements(std::vector<int> &_vector, int index1, int index2){
    // https://www.tutorialspoint.com/how-to-swap-two-arrays-without-using-temporary-variable-in-c-language
    _vector[index1] = _vector[index1] + _vector[index2];
    _vector[index2] = _vector[index1] - _vector[index2];
    _vector[index1] = _vector[index1] - _vector[index2];
}

void PrefixSum(std::vector<int> &_vector){
    for (int i = 1; i < _vector.size(); ++i) {
        _vector[i] = _vector[i - 1] + _vector[i];
    }
}

