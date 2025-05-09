#pragma once
#pragma once
#include "TextFilterStrategy.h"
#include <memory>
#include <string>

class TextProcessor {
public:
    explicit TextProcessor(std::unique_ptr<TextFilterStrategy> init = nullptr);
    void setStrategy(std::unique_ptr<TextFilterStrategy> newStrat);
    void setText(const std::string& text);
    std::string getOriginalText() const;
    std::string processText() const;
private:
    std::unique_ptr<TextFilterStrategy> strategy;
    std::string originalText;
};
