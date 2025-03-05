#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n + whole * d, d) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    simplify();
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    int whole = mf.getNumerator() / mf.getDenominator();
    int num = abs(mf.getNumerator() % mf.getDenominator());
    int den = mf.getDenominator();

    if (whole != 0)
        out << whole;

    if (num != 0) {
        if (whole != 0) out << " ";
        out << num << "/" << den;
    }

    if (whole == 0 && num == 0)
        out << "0";

    return out;
}
#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n + whole * d, d) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    simplify();
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    int whole = mf.getNumerator() / mf.getDenominator();
    int num = abs(mf.getNumerator() % mf.getDenominator());
    int den = mf.getDenominator();

    if (whole != 0)
        out << whole;

    if (num != 0) {
        if (whole != 0) out << " ";
        out << num << "/" << den;
    }

    if (whole == 0 && num == 0)
        out << "0";

    return out;
}

