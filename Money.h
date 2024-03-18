#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Money {
private:
    long hryvnia;
    unsigned char kopiyky;

public:
    Money();
    Money(long hryvnia, unsigned char kopiyky);
    Money(const Money& second);

    long GetHryvnia() const { return hryvnia; }
    unsigned char GetKopiyky() const { return kopiyky; }

    Money operator+(const Money& secondValue) const;
    Money operator-(const Money& secondValue) const;
    Money operator/(int divisor) const;
    Money operator/(double divisor) const;
    Money operator*(double multiplier) const;
    bool operator==(const Money& secondValue) const;
    bool operator<(const Money& secondValue) const;
    bool operator>(const Money& secondValue) const;
    Money& operator=(const Money& other); 

    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    friend istream& operator>>(istream& in, Money& money);
    friend ostream& operator<<(ostream& out, const Money& money);
};
