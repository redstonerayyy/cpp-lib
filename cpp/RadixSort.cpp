//
// Created by anton on 12/10/22.
//
// https://www.codingeek.com/algorithms/radix-sort-explanation-pseudocode-and-implementation/

#include "RadixSort.hpp"
#include "DataStructureUtils.hpp"

#include <iostream>

// count occurence of digit at certain positon determined by placedivider
std::vector<int> CountingRoutine(std::vector<int> &_vector, int placedivider){
    // count digits 0 - 9
    std::vector<int> counters(10, 0);
    for (int i : _vector) {
        // get digit at certain place, e. g. 303/10 = 30.3, 30.3 % 10 = 0
        // digit at second position from the right is 0
        counters[ (i/placedivider) % 10 ]++;
    }
    return counters;
}

// the one and only superfast radix sort
void RadixSort(std::vector<int> &_vector) {
    // start at right most digit
    int digitplace = 1;
    // resulting array, will be used in the algorithm to store partially
    // sorted copy of the original array
    std::vector<int> result(_vector.size());
    // get max value
    int max = GetMax(_vector);

    // stop if no digits are at this position
    while(max/digitplace > 0){
        // calculate counters, return a 10 element vector
        std::vector<int> counters = CountingRoutine(_vector, digitplace);
        // apply prefixsum to this vector
        PrefixSum(counters);
        //rebuilt the new array based on this sorting pass
        for (int i = _vector.size() - 1; i >= 0; i--) {
            // get the value of the prefixsum array at the position
            // for the current digit and subtract 1 from it,
            // so it points to the true index
            counters[ (_vector[i]/digitplace) % 10 ]--;
            // place the element of the original vector at this position
            // which is now in the prefixsum array, so it is at the right
            // position for this digit pass
            result[ counters[ (_vector[i]/digitplace) % 10 ] ] = _vector[i];
        }
        // copy to original array
        for (unsigned long i = 0; i < _vector.size(); ++i) {
            _vector[i] = result[i];
        }

        digitplace *= 10;
    }
}
