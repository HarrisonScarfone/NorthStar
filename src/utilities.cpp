#include <iostream>
#include <string>
#include <vector>

namespace Utilities {
namespace StringHandlers {
    std::vector<std::string> TokenizeByDelimiter(std::string str, std::string delimiter) {
        std::vector<std::string> token_vector;
        while (str.size()) {
            int index = str.find(delimiter);
            if (index != std::string::npos) {
                token_vector.push_back(str.substr(0, index));
                str = str.substr(index + delimiter.size());
                if (str.size() == 0) token_vector.push_back(str);
            } else {
                token_vector.push_back(str);
                str = "";
            }
        }
        return token_vector;
    }
}  // namespace StringHandlers
}  // namespace Utilities
