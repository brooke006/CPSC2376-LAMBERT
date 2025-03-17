#include "MixedFraction.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Fraction Calculator" << endl;
    Fraction f1(3, 4), f2(2, 5);
    MixedFraction m1(f1), m2(f2);

    cout << "Fraction 1: " << m1 << endl;
    cout << "Fraction 2: " << m2 << endl;

    Fraction result = m1 + m2;
    cout << "Sum: " << MixedFraction(result) << endl;

    // Further UI implementation...
    return 0;
}
