#include "ReverseStrategy.h"
#include <algorithm>

std::string ReverseStrategy::process(const std::string& text) const {
    std::string result = text;
    std::reverse(result.begin(), result.end());
    return result;
}

std::string ReverseStrategy::getName() const {
    return "Reverse";
}
