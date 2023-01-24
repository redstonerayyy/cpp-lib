#include "max/max.hpp"

#include <vector>
#include <iostream>

void TestMax(){
    std::vector<short> vshort = {8, 13, 1, 0, 5, 6};
    std::vector<int> vint = {325, 13, 43, 34, 56, 54};
    std::vector<long> vlong = {675, 13, 34, 40, 29, 6};
    std::vector<float> vfloat = {8.0f, 13.0f, 1.0f, 0.0f, 5.0f, 6.0f};
    std::vector<double> vdouble = {9.0f, 93.0f, 84.0f, 30.0f, 5.0f, 5.0f};
    // test max
    std::cout << Max::GetMax(vshort) << " expect 13\n";
    std::cout << Max::GetMax(vint) << " expect 325\n";
    std::cout << Max::GetMax(vlong) << " expect 675\n";
    std::cout << Max::GetMax(vfloat) << " expect 13.0\n";
    std::cout << Max::GetMax(vdouble) << " expect 93.0\n";
}
