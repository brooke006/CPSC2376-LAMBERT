#include "Fraction.h"
#include <stdexcept>

Fraction::Fraction() : num(0), den(1) {}  // Initialize to 0/1

Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    simplify();
}

int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    den = d;
    simplify();
}

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
    if (den < 0) {
        den = -den;
        num = -num;
    }
}

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
        throw std::invalid_argument("Attempt to divide by zero fraction");
    }
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.num << "/" << f.den;