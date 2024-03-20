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
    void SetHryvnia(long value) { hryvnia = value; }
    void SetKopiyky(unsigned char value) { kopiyky = value; }

    friend Money operator+(const Money& firstValue, const Money& secondValue);
    friend Money operator-(const Money& firstValue, const Money& secondValue);
    friend Money operator/(const Money& value, int divisor);
    friend Money operator/(const Money& value, double divisor);
    friend Money operator*(const Money& value, double multiplier);
    friend bool operator==(const Money& firstValue, const Money& secondValue);
    friend bool operator<(const Money& firstValue, const Money& secondValue);
    friend bool operator>(const Money& firstValue, const Money& secondValue);

    Money& operator=(const Money& other); 
    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);
    friend istream& operator>>(istream& in, Money& money);
    friend ostream& operator<<(ostream& out, const Money& money);
};
