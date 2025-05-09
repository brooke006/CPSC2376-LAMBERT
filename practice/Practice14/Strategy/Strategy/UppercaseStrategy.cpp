#include "UppercaseStrategy.h"
#include <algorithm>
#include <cctype>

std::string UppercaseStrategy::process(const std::string& text) const {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return std::toupper(c); });
    return result;
}

std::string UppercaseStrategy::getName() const {
    return "Uppercase";
}
