#include <iostream>

#ifndef FRACTION_H
#define	FRACTION_H

class Fraction {
    public:
        explicit Fraction(int n = 0, int d = 1);
        // TODO Fraction(std::string s) ???
        ~Fraction();

        Fraction& operator+=(const Fraction& rhs);
        Fraction& operator-=(const Fraction& rhs);
        Fraction& operator*=(const Fraction& rhs);
        Fraction& operator/=(const Fraction& rhs);
        
        operator double() { return static_cast<double>(numerator) / denominator; };
        int get_numerator() const { return numerator; }
        int get_denominator() const { return denominator; }
        
    private:
        int numerator;
        int denominator;
        void simplify();
        static int gcd(int a, int b);
};

Fraction operator+(Fraction lhs, const Fraction& rhs);
Fraction operator-(Fraction lhs, const Fraction& rhs);
Fraction operator*(Fraction lhs, const Fraction& rhs);
Fraction operator/(Fraction lhs, const Fraction& rhs);

bool operator==(const Fraction& lhs, const Fraction& rhs);
bool operator!=(const Fraction& lhs, const Fraction& rhs);
bool operator<(const Fraction& lhs, const Fraction& rhs);
bool operator>(const Fraction& lhs, const Fraction& rhs);
std::ostream& operator<<(std::ostream& os, const Fraction& f);

#endif	/* FRACTION_H */
