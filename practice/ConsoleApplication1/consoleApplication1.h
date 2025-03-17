#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator
    void simplify(); // Helper function to simplify the fraction using the Euclidean algorithm

public:
    Fraction(); // Default constructor
    Fraction(int n, int d); // Parameterized constructor

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int n);
    void setDenominator(int d);

    // Friend functions for operator overloads
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif
