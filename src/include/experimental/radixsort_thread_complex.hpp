#pragma once

#include <vector>

void CountingRoutine(std::vector<int> &_vector, std::vector<int> &_counters, int placedivider, int start, int end);
void RadixSortComplexThread(std::vector<int> &_vector);
void RadixSort(std::vector<int> &_vector, std::vector<int> &_result, int start, int end);
