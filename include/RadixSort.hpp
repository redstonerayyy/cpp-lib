//
// Created by anton on 12/10/22.
//

#ifndef CPP_ALGOS_RADIXSORT_HPP
#define CPP_ALGOS_RADIXSORT_HPP

#include <vector>
#include <array>

void CountingRoutine(std::vector<int> &_vector, int placedivider, int start, int end, std::vector<int> &_counters_array, int counters_start);
void RadixSort(std::vector<int> &_vector);

#endif //CPP_ALGOS_RADIXSORT_HPP
