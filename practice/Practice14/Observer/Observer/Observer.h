#pragma once
#pragma once
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(double grade) = 0;
    virtual std::string getName() const = 0;
};
