#pragma once
#include "Fraction.h"

// Default constructor
Fraction::Fraction() : num(0), den(1) {}

// Parameterized constructor
Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

// Getters
int Fraction::getNumerator() const { return num; }
int Fraction::getDenominator() const { return den; }

// Setters
void Fraction::setNumerator(int n) { num = n; simplify(); }
void Fraction::setDenominator(int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    den = d;
    simplify();
}

// Simplify function using Euclidean Algorithm
void Fraction::simplify() {
    int a = num, b = den;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;

    // Ensure denominator is always positive
    if (den < 0) {
        den = -den;
        num = -num;
    }
}

// Arithmetic Operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den - rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) {
        throw std::invalid_argument("Attempt to divide by zero.");
    }
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

// Comparison Operators
bool Fraction::operator==(const Fraction& other) const { return num * other.den == other.num * den; }
bool Fraction::operator!=(const Fraction& other) const { return !(*this == other); }
bool Fraction::operator<(const Fraction& other) const { return num * other.den < other.num * den; }
bool Fraction::operator>(const Fraction& other) const { return other < *this; }
bool Fraction::operator<=(const Fraction& other) const { return !(other < *this); }
bool Fraction::operator>=(const Fraction& other) const { return !(*this < other); }

// Overloaded << Operator for Printing
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;
    return out;
}
