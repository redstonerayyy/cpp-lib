//
// Created by anton on 12/10/22.
//
// https://www.codingeek.com/algorithms/radix-sort-explanation-pseudocode-and-implementation/

#include "RadixSort.hpp"
#include "DataStructureUtils.hpp"

#include <thread>

// count occurence of digit at certain positon determined by placedivider
void CountingRoutine(std::vector<int> &_vector, int placedivider, int start, int end, std::vector<int> &_counters_array, int counters_start){
    // count digits 0 - 9
    std::cout << start << ":" << end << "\n";
    for (int i = start; i < end; ++i) {

        // get digit at certain place, e. g. 303/10 = 30.3, 30.3 % 10 = 0
        // digit at second position from the right is 0
        _counters_array[ counters_start + (_vector[i]/placedivider) % 10 ]++;
    }
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
        // multithreaded
        std::vector<int> counters_array(10 * 10, 0);
        std::vector<std::thread> threads(10);
        // spawn 10 threads
        int range_per_thread = int(_vector.size() / 10);
        int additional = int(_vector.size() % 10);
        // last thread uses additional
        threads[9] = std::thread (CountingRoutine, std::ref(_vector), digitplace, 9 * range_per_thread, 9 * range_per_thread + range_per_thread + additional, std::ref(counters_array), 9 * 10);
        for(int i = 0; i < 9; ++i){
            // calculate counters, return a 10 element vector
            threads[i] = std::thread (CountingRoutine, std::ref(_vector), digitplace, i * range_per_thread, i * range_per_thread + range_per_thread, std::ref(counters_array), i * 10);
        }

        // join the threads
        for(int i = 0; i < 10; ++i){
            threads[i].join();
        }


        // add up results of the threads
        std::vector<int> counters(10, 0);
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                counters[j] += counters_array[i * 10 + j];
            }
        }

        // apply prefixsum to this vector
        PrefixSum(counters);

        std::cout << "starting rebuild" << std::endl;
        //rebuilt the new array based on this sorting pass
        for (int i = int(_vector.size()) - 1; i >= 0; i--) {
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
        std::cout << "ending rebuild" << std::endl;

        digitplace *= 10;
    }
}
