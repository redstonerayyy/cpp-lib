#include <iostream>
#include <vector>

#include "RadixSort.hpp"

int main() {
    std::vector<int> test = {1,6,4,5,7,8,5,4,6,7,5,3,5};
    RadixSort(test);
    for (int i : test) {
        std::cout << i << std::endl;
    }
}
