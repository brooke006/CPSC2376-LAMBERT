#include "NotifierObserver.h"
#include <iostream>

NotifierObserver::NotifierObserver(double thresh)
    : threshold(thresh) {
}

void NotifierObserver::update(double grade) {
    if (grade < threshold) {
        std::cout << "EMAIL ALERT: Grade " << grade
            << "% below threshold of " << threshold
            << "%. Email sent to student@example.com\n";
    }
}

std::string NotifierObserver::getName() const {
    return "NotifierObserver (thr=" + std::to_string(threshold) + "%)";
}

void NotifierObserver::setThreshold(double t) {
    threshold = t;
}
