#pragma once
#pragma once
#include <string>

class TextFilterStrategy {
public:
    virtual ~TextFilterStrategy() = default;
    virtual std::string process(const std::string& text) const = 0;
    virtual std::string getName() const = 0;
};
