#pragma once

#include <cstdint>
#include <vector>
#include <array>

namespace Print {

template <typename T>
T PrintOneDimensionalSequence(std::vector<T> &vector);

template <typename T, std::uint64_t N>
T PrintOneDimensionalSequence(std::array<T, N> &stdarray);

template <typename T>
T PrintOneDimensionalSequence(T array[], std::uint64_t size);

}
