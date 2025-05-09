#include "RemoveVowelsStrategy.h"
#include <algorithm>
#include <cctype>
#include <iterator>

std::string RemoveVowelsStrategy::process(const std::string& text) const {
    std::string result;
    std::copy_if(text.begin(), text.end(), std::back_inserter(result),
        [](char c) {
            char lower = std::tolower(static_cast<unsigned char>(c));
            return lower != 'a' && lower != 'e' && lower != 'i'
                && lower != 'o' && lower != 'u';
        });
    return result;
}

std::string RemoveVowelsStrategy::getName() const {
    return "Remove Vowels";
}
