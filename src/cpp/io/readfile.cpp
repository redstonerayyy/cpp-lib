#include "io/readfile.hpp"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <optional>

namespace IO {

std::optional<std::string> ReadFileIntoString(std::string filename){
    std::ifstream infile(filename);
    if(!infile){
        std::cout << "ERROR: Could not read file" << filename << "\n";
        return{};
    }
    std::stringstream stringstream;
    stringstream << infile.rdbuf();
    return stringstream.str();
}

}
