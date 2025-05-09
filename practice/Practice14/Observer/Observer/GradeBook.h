#pragma once
#pragma once
#include "Observer.h"
#include <memory>
#include <vector>
#include <string>

class GradeBook {
public:
    explicit GradeBook(const std::string& name = "Student");
    void attach(std::unique_ptr<Observer> obs);
    void addGrade(double grade);
    const std::vector<double>& getGrades() const;
private:
    void notifyObservers(double grade);
    std::string studentName;
    std::vector<std::unique_ptr<Observer>> observers;
    std::vector<double> grades;
};
