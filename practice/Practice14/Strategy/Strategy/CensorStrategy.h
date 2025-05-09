#pragma once
#pragma once
#include "TextFilterStrategy.h"
#include <set>
#include <string>

class CensorStrategy : public TextFilterStrategy {
public:
    CensorStrategy();
    std::string process(const std::string& text) const override;
    std::string getName() const override;
private:
    std::set<std::string> badWords;
};
