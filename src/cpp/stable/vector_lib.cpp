#include "vector_lib.hpp"

#include <iostream>
#include <vector>

// find largest value in vector integers
int GetMaxRange(std::vector<int> &_vector, int start, int end){
    int max = _vector[0];
    for (int i = start; i < end; ++i) {
        if(_vector[i] > max){
            max = _vector[i];
        }
    }
    return max;
}

// find largest value in vector of integers
int GetMax(std::vector<int> &_vector){
    int max = _vector[0];
    for (int i = 0; i < _vector.size(); ++i) {
        if(_vector[i] > max){
            max = _vector[i];
        }
    }
    return max;
}

// swap two elements, modifies the referenced vector
// https://www.tutorialspoint.com/how-to-swap-two-arrays-without-using-temporary-variable-in-c-language
// use in place swap trick without temporary variable
void SwapElementsInt(std::vector<int> &_vector, int index1, int index2){
    _vector[index1] = _vector[index1] + _vector[index2];
    _vector[index2] = _vector[index1] - _vector[index2];
    _vector[index1] = _vector[index1] - _vector[index2];
}

// swap two elements regardless of type or value
template <typename T>
void SwapElements(std::vector<T> &_vector, int index1, int index2){
    T temp = _vector[index1];
    _vector[index1] = _vector[index2];
    _vector[index2] = temp;
}

// calculate prefixsum on a vector of intergers
void PrefixSum(std::vector<int> &_vector){
    for (int i = 1; i < _vector.size(); ++i) {
        _vector[i] = _vector[i - 1] + _vector[i];
    }
}

// print elements of a vector seperated by a " "
template <typename T>
void PrintVector(std::vector<T> &_vector){
    for (T i : _vector) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
