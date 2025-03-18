#pragma once
#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
protected:
    int num; // Numerator
    int den; // Denominator
    void simplify(); // Simplifies the fraction using GCD

public:
    // Constructors
    Fraction();
    Fraction(int n, int d);

    // Getters and Setters
    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d);

    // Arithmetic Operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Comparison Operators
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    // Stream Overloading
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
