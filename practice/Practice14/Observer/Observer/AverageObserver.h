#pragma once
#pragma once
#include "Observer.h"
#include <vector>

class AverageObserver : public Observer {
public:
    void update(double grade) override;
    std::string getName() const override;
private:
    std::vector<double> grades;
};
