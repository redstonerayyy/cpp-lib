#pragma once

#include <string>
#include <optional>

namespace IO {

std::optional<std::string> ReadFileIntoString(std::string filename);

}
