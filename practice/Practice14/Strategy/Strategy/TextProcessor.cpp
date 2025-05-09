#include "TextProcessor.h"

TextProcessor::TextProcessor(std::unique_ptr<TextFilterStrategy> init)
    : strategy(std::move(init)) {
}

void TextProcessor::setStrategy(std::unique_ptr<TextFilterStrategy> newStrat) {
    strategy = std::move(newStrat);
}

void TextProcessor::setText(const std::string& text) {
    originalText = text;
}

std::string TextProcessor::getOriginalText() const {
    return originalText;
}

std::string TextProcessor::processText() const {
    if (!strategy) return originalText;
    return strategy->process(originalText);
}
