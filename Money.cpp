#include "Money.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Money::Money() {
    hryvnia = 0;
    kopiyky = 0;
}

Money::Money(long hryvnia, unsigned char kopiyky) {
    this->hryvnia = hryvnia;
    this->kopiyky = kopiyky;
}

Money::Money(const Money& second) {
    hryvnia = second.hryvnia;
    kopiyky = second.kopiyky;
}

Money& Money::operator=(const Money& other) {
    if (this == &other)
        return *this;

    hryvnia = other.hryvnia;
    kopiyky = other.kopiyky;

    return *this;
}

istream& operator>>(istream& in, Money& money) {
    cout << "Enter amount in hryvnia: ";
    in >> money.hryvnia;

    cout << "Enter amount in kopiyky: ";
    in >> money.kopiyky;

    return in;
}

ostream& operator<<(ostream& out, const Money& money) {
    out << money.hryvnia << " hryvnia " << static_cast<int>(money.kopiyky) << " kopiyok";
    return out;
}

Money operator+(const Money& firstValue, const Money& secondValue) {
    long totalHryvnia = firstValue.hryvnia + secondValue.hryvnia;
    int totalKopiyky = firstValue.kopiyky + secondValue.kopiyky;

    if (totalKopiyky >= 100) {
        totalHryvnia += totalKopiyky / 100;
        totalKopiyky %= 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money operator-(const Money& firstValue, const Money& secondValue) {
    long totalHryvnia = firstValue.hryvnia - secondValue.hryvnia;
    int totalKopiyky = firstValue.kopiyky - secondValue.kopiyky;

    if (totalKopiyky < 0) {
        totalHryvnia -= 1;
        totalKopiyky += 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money operator/(const Money& value, int divisor) {
    long totalHryvnia = value.hryvnia / divisor;
    int totalKopiyky = (value.hryvnia % divisor) * 100 / divisor + value.kopiyky / divisor;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money operator/(const Money& value, double divisor) {
    double totalMoney = static_cast<double>(value.hryvnia * 100 + value.kopiyky) / divisor;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money operator*(const Money& value, double multiplier) {
    double totalMoney = static_cast<double>(value.hryvnia * 100 + value.kopiyky) * multiplier;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

bool operator==(const Money& firstValue, const Money& secondValue) {
    return firstValue.hryvnia == secondValue.hryvnia && firstValue.kopiyky == secondValue.kopiyky;
}

bool operator<(const Money& firstValue, const Money& secondValue) {
    if (firstValue.hryvnia == secondValue.hryvnia) {
        return firstValue.kopiyky < secondValue.kopiyky;
    }
    return firstValue.hryvnia < secondValue.hryvnia;
}

bool operator>(const Money& firstValue, const Money& secondValue) {
    if (firstValue.hryvnia == secondValue.hryvnia) {
        return firstValue.kopiyky > secondValue.kopiyky;
    }
    return firstValue.hryvnia > secondValue.hryvnia;
}

Money& Money::operator++() {
    ++hryvnia;
    return *this;
}

Money Money::operator++(int) {
    Money m(*this);
    ++kopiyky;
    if (kopiyky == 100) {
        ++hryvnia;
        kopiyky = 0;
    }
    return m;
}

Money& Money::operator--() {
    --hryvnia;
    return *this;
}

Money Money::operator--(int) {
    Money m(*this);
    if (kopiyky == 0) {
        --hryvnia;
        kopiyky = 99;
    } else {
        --kopiyky;
    }
    return m;
}
