#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

namespace Utilities {
namespace StringHandlers {
    std::vector<std::string> TokenizeByDelimiter(std::string str, std::string delimiter);
}
}  // namespace Utilities

#endif