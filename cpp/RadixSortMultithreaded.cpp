//
// Created by anton on 17/10/22.
//

#include "RadixSortMultithreaded.hpp"
#include "DataStructureUtils.hpp"

#include <thread>
#include <limits>

void MergeVectorParts(std::vector<int> &_vector, std::vector<std::pair<int, int>> &_parts){
    // https://medium.com/outco/how-to-merge-k-sorted-arrays-c35d87aa298e
    // use binary min heap
    std::vector<int> merged(_vector.size());
    std::vector<std::pair<int, int>> binary_heap(_parts.size());
    // construct binary heap
    for (int i = 0; i < _parts.size(); ++i) {
        // pair with arraynumber, value
        binary_heap.at(i) = { i, _vector.at(_parts.at(i).first) };
        _parts.at(i).first++;
    }
    // sort binary heap
    for (int i = 1; i < binary_heap.size(); ++i) {
        int j = i;
        while(binary_heap.at(int( (j - 1) / 2 )).second > binary_heap.at(j).second) {
            // swap parent with child
            std::pair<int, int> temp = binary_heap.at(int( (j - 1) / 2 ));
            binary_heap.at(int( (j - 1) / 2 )) = binary_heap.at(j);
            binary_heap.at(j) = temp;
            j = int( (j - 1) / 2 );
        }
    }
    for (auto i: binary_heap) {
        std::cout << i.first << ":" << i.second << "\n";
    }

    // fill merged list
    int fillindex = 0;
    while(binary_heap.at(0).second < 1000){
        // store array id of the first element
        std::pair<int, int> heapfirst = binary_heap.at(0);
        // add the smallest element in heap to final array
        merged.at(fillindex) = heapfirst.second;
        std::cout << heapfirst.first << ":" << _parts.at(heapfirst.first).first << ":" << _parts.at(heapfirst.first).second << "\n";
        // check if there is an element left in the lift, where the current elemement got removed
        if (_parts.at(heapfirst.first).first < _parts.at(heapfirst.first).second){
            // replace the current element with this element and increment the counter
            // for this part of the original vector
            binary_heap.at(0) = { heapfirst.first, _vector.at(_parts.at(heapfirst.first).first) };
            _parts.at(heapfirst.first).first++;
        } else {
            // mark this list as finished by setting the value to the "infinity"
            binary_heap.at(0).second = 1000;// std::numeric_limits<int>::max();
        }
        // sort again
        for (int i = 1; i < binary_heap.size(); ++i) {
            int j = i;
            while(binary_heap.at(int( (j - 1) / 2 )).second > binary_heap.at(j).second) {
                // swap parent with child
                std::pair<int, int> temp = binary_heap.at(int( (j - 1) / 2 ));
                binary_heap.at(int( (j - 1) / 2 )) = binary_heap.at(j);
                binary_heap.at(j) = temp;
                j = int( (j - 1) / 2 );
            }
        }
        for (auto i: binary_heap) {
            std::cout << i.first << ":" << i.second << "\n";
        }
        std::cout << "fill" << fillindex << std::endl;
        fillindex++;
    }
    PrintVector(merged);
}

// count occurence of digit at certain positon determined by placedivider
void CountingRoutine(std::vector<int> &_vector, std::vector<int> &_counters, int placedivider, int start, int end){
    // count digits 0 - 9
    // std::cout << start << ":" << end << "\n";
    for (int i = start; i < end; ++i) {

        // get digit at certain place, e. g. 303/10 = 30.3, 30.3 % 10 = 0
        // digit at second position from the right is 0
        _counters[ (_vector[i]/placedivider) % 10 ]++;
    }
}

void RadixSortMultithreaded(std::vector<int> &_vector){
    std::vector<int> result(_vector.size());

    int threadcount = 10;
    std::vector<std::pair<int, int>> parts(threadcount);
    std::vector<std::thread> threads(threadcount);
    // spawn 10 threads
    int range_per_thread = int(_vector.size() / threadcount);
    int additional = int(_vector.size() % threadcount);
    // last thread uses additional
    threads[threadcount - 1] = std::thread (RadixSort, std::ref(_vector), std::ref(result), (threadcount - 1) * range_per_thread, (threadcount - 1) * range_per_thread + range_per_thread + additional);
    parts[threadcount - 1] = {(threadcount - 1) * range_per_thread, (threadcount - 1) * range_per_thread + range_per_thread + additional};

    for(int i = 0; i < threadcount - 1; ++i){
        // calculate counters, return a 10 element vector
        threads[i] = std::thread (RadixSort, std::ref(_vector), std::ref(result), i * range_per_thread, i * range_per_thread + range_per_thread);
        parts[i] = {i * range_per_thread, i * range_per_thread + range_per_thread};
    }

    // join the threads
    for(int i = 0; i < 10; ++i){
        threads[i].join();
    }



    //parts of array are sorted
    PrintVector(_vector);
//    MergeVectorParts(_vector, parts);
}

// the one and only superfast radix sort
void RadixSort(std::vector<int> &_vector, std::vector<int> &_result, int start, int end) {
    // start at right most digit
    int digitplace = 1;
    // get max value
    int max = GetMaxRange(_vector, start, end);

    // stop if no digits are at this position
    while(max/digitplace > 0){

        // add up results of the threads
        std::vector<int> counters(10, 0);
        CountingRoutine(_vector, counters, digitplace, start, end);

        // apply prefixsum to this vector
        PrefixSum(counters);

        //rebuilt the new array based on this sorting pass
        for (int i = end - 1; i >= start; i--) {
            // get the value of the prefixsum array at the position
            // for the current digit and subtract 1 from it,
            // so it points to the true index
            int digit = (_vector[i]/digitplace) % 10;
            counters[ digit ]--;
            // place the element of the original vector at this position
            // which is now in the prefixsum array, so it is at the right
            // position for this digit pass
            _result[ start + counters[ digit ] ] = _vector[i];
        }

        // copy to original array
        for (unsigned long i = start; i < end; ++i) {
            _vector[i] = _result[i];
        }

        digitplace *= 10;
    }
}
