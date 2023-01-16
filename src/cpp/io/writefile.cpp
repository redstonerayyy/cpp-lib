#include "io/writefile.hpp"

#include <string>
#include <fstream>
#include <iostream>

namespace IO {

void WriteStringToFile(std::string filename, std::string data){
    std::ofstream outfile(filename);
    if(!outfile){
        std::cout << "ERROR: Could not open file" << filename << "\n";
        return;
    }
    outfile << data;
}

}