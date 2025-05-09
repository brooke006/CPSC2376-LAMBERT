#pragma once
#pragma once
#include "TextFilterStrategy.h"

class RemoveVowelsStrategy : public TextFilterStrategy {
public:
    std::string process(const std::string& text) const override;
    std::string getName() const override;
};
