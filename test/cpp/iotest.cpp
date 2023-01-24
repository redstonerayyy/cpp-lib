#include "io/readfile.hpp"
#include "io/writefile.hpp"

#include <string>
#include <iostream>

void TestIO(){
    // std::string data = IO::ReadFileIntoString("filetoread.txt"); // not implemented yet
    // std::cout << (data == "Read this file!") << "\n"
    std::string content = "Write this file!";
    IO::WriteStringToFile("runtests/filetowrite.txt", content);
}
