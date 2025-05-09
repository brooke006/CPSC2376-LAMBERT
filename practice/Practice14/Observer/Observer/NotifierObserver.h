#pragma once
#include "Observer.h"

class NotifierObserver : public Observer {
public:
    explicit NotifierObserver(double threshold = 60.0);
    void update(double grade) override;
    std::string getName() const override;
    void setThreshold(double t);
private:
    double threshold;
};
