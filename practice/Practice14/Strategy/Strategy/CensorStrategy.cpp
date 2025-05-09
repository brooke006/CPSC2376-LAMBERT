#include "CensorStrategy.h"
#include <sstream>

CensorStrategy::CensorStrategy()
    : badWords{ "bad", "ugly", "evil", "inappropriate" } {
}

std::string CensorStrategy::process(const std::string& text) const {
    std::istringstream iss(text);
    std::ostringstream oss;
    std::string word;
    bool first = true;
    while (iss >> word) {
        if (!first) oss << " ";
        if (badWords.count(word)) oss << "****";
        else oss << word;
        first = false;
    }
    return oss.str();
}

std::string CensorStrategy::getName() const {
    return "Censor Bad Words";
}
