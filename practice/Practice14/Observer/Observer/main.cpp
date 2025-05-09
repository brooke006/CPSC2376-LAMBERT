#include "GradeBook.h"
#include "AverageObserver.h"
#include "NotifierObserver.h"
#include <iostream>
#include <limits>
#include <memory>

int getChoice(int min, int max) {
    int c;
    while (true) {
        std::cout << "Select an option: ";
        if (std::cin >> c && c >= min && c <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return c;
        }
        std::cout << "Invalid. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << "Grade Book System\n";
    std::cout << "Enter student name: ";
    std::string name;
    std::getline(std::cin, name);

    GradeBook gb(name);

    auto avgObs = std::make_unique<AverageObserver>();
    auto notifObs = std::make_unique<NotifierObserver>(60.0);
    NotifierObserver* notifPtr = notifObs.get();

    gb.attach(std::move(avgObs));
    gb.attach(std::move(notifObs));

    while (true) {
        std::cout << "\n1. Add grade\n2. Change threshold\n3. View all grades\n4. Exit\n";
        int ch = getChoice(1, 4);
        if (ch == 1) {
            std::cout << "Enter grade (0–100): ";
            double g; std::cin >> g;
            gb.addGrade(g);
        }
        else if (ch == 2) {
            std::cout << "New threshold: ";
            double t; std::cin >> t;
            notifPtr->setThreshold(t);
            std::cout << "Threshold now " << t << "%\n";
        }
        else if (ch == 3) {
            std::cout << "Grades: ";
            for (double g : gb.getGrades()) std::cout << g << " ";
            std::cout << "\n";
        }
        else break;
    }
    return 0;
}
