#include "GradeBook.h"
#include <iostream>

GradeBook::GradeBook(const std::string& name)
    : studentName(name) {
}

void GradeBook::attach(std::unique_ptr<Observer> obs) {
    std::cout << obs->getName() << " attached to " << studentName << "\n";
    observers.push_back(std::move(obs));
}

void GradeBook::addGrade(double grade) {
    if (grade < 0 || grade > 100) {
        std::cout << "Invalid grade. Must be 0–100.\n";
        return;
    }
    grades.push_back(grade);
    std::cout << "Added grade " << grade << "% for " << studentName << "\n";
    notifyObservers(grade);
}

const std::vector<double>& GradeBook::getGrades() const {
    return grades;
}

void GradeBook::notifyObservers(double grade) {
    for (auto& o : observers) o->update(grade);
}
