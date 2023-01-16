#pragma once

#include <cstdint>
#include <vector>

namespace Max {

template <typename T>
T GetMax(std::vector<T> &vector);

// start and end are both inclusive
template <typename T>
T GetMaxInRange(std::vector<T> &vector, std::uint64_t start, std::uint64_t end);

}
