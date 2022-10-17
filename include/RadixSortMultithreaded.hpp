//
// Created by anton on 17/10/22.
//

#ifndef CPP_ALGOS_RADIXSORTMULTITHREADED_HPP
#define CPP_ALGOS_RADIXSORTMULTITHREADED_HPP

#include <vector>

void CountingRoutine(std::vector<int> &_vector, std::vector<int> &_counters, int placedivider, int start, int end);
void RadixSortMultithreaded(std::vector<int> &_vector);
void RadixSort(std::vector<int> &_vector, std::vector<int> &_result, int start, int end);

#endif //CPP_ALGOS_RADIXSORTMULTITHREADED_HPP
