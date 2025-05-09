#include "AverageObserver.h"
#include <numeric>
#include <iostream>

void AverageObserver::update(double grade) {
    grades.push_back(grade);
    double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
    double avg = sum / grades.size();
    std::cout << "Average updated: " << avg << "%\n";
}

std::string AverageObserver::getName() const {
    return "AverageObserver";
}
