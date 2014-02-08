#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Fraction.h"

//  numerator
// -----------
// denominator

Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
    if (d == 0)
        throw std::domain_error("Division by zero not allowed");
    // denominator should be positive
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    //std::cout << "DEBUG: Fraction " << numerator << '/' << denominator << " created" << std::endl;
}

Fraction::~Fraction() {
    //std::cout << "DEBUG: Fraction " << numerator << '/' << denominator << " destroyed" << std::endl;
}

Fraction& Fraction::operator+=(const Fraction& rhs) {
    numerator = numerator * rhs.denominator + denominator * rhs.numerator;
    denominator *= rhs.denominator;
    this->simplify();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs) {
    numerator = numerator * rhs.denominator - denominator * rhs.numerator;
    denominator *= rhs.denominator;
    this->simplify();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& rhs) {
    numerator *= rhs.numerator;
    denominator *= rhs.denominator;
    this->simplify();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs) {
    if (rhs.numerator == 0)
        throw std::domain_error("Division by zero not allowed");
    numerator *= rhs.denominator;
    denominator *= rhs.numerator;
    this->simplify();
    return *this;
}

void Fraction::simplify() {
    if (numerator == 0) {
        denominator = 1;
    } else {
        int div = gcd(abs(numerator), abs(denominator));
        if (div != 1) {
            numerator /= div;
            denominator /= div;
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }
}

int Fraction::gcd(int a, int b) {
    int temp = 0;
    while ((temp = std::max(a, b) % std::min(a, b)) != 0) {
        a = std::min(a, b);
        b = temp;
    }
    return std::min(a, b);
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.get_numerator() << "/" << f.get_denominator();
    return os;
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return lhs.get_numerator() == rhs.get_numerator() && lhs.get_denominator() == rhs.get_denominator();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
    return !operator ==(lhs, rhs);
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return (static_cast<double>(lhs.get_numerator()) / lhs.get_denominator()) < (static_cast<double>(rhs.get_numerator()) / rhs.get_denominator());
}

bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return !(lhs < rhs || lhs == rhs);
}

Fraction operator+(Fraction lhs, const Fraction& rhs) {
    lhs += rhs;
    return lhs;
}

Fraction operator-(Fraction lhs, const Fraction& rhs) {
    lhs -= rhs;
    return lhs;
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
    lhs *= rhs;
    return lhs;
}

Fraction operator/(Fraction lhs, const Fraction& rhs) {
    lhs /= rhs;
    return lhs;
}
