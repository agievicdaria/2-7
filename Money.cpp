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

Money Money::operator+(const Money& secondValue) const {
    long totalHryvnia = hryvnia + secondValue.hryvnia;
    int totalKopiyky = kopiyky + secondValue.kopiyky;

    if (totalKopiyky >= 100) {
        totalHryvnia += totalKopiyky / 100;
        totalKopiyky %= 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::operator-(const Money& secondValue) const {
    long totalHryvnia = hryvnia - secondValue.hryvnia;
    int totalKopiyky = kopiyky - secondValue.kopiyky;

    if (totalKopiyky < 0) {
        totalHryvnia -= 1;
        totalKopiyky += 100;
    }

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::operator/(int divisor) const {
    long totalHryvnia = hryvnia / divisor;
    int totalKopiyky = (hryvnia % divisor) * 100 / divisor + kopiyky / divisor;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::operator/(double divisor) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) / divisor;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

Money Money::operator*(double multiplier) const {
    double totalMoney = static_cast<double>(hryvnia * 100 + kopiyky) * multiplier;
    long totalHryvnia = static_cast<long>(totalMoney) / 100;
    int totalKopiyky = static_cast<int>(totalMoney) % 100;

    return Money(totalHryvnia, static_cast<unsigned char>(totalKopiyky));
}

bool Money::operator==(const Money& secondValue) const {
    return hryvnia == secondValue.hryvnia && kopiyky == secondValue.kopiyky;
}

bool Money::operator<(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky < secondValue.kopiyky;
    }
    return hryvnia < secondValue.hryvnia;
}

bool Money::operator>(const Money& secondValue) const {
    if (hryvnia == secondValue.hryvnia) {
        return kopiyky > secondValue.kopiyky;
    }
    return hryvnia > secondValue.hryvnia;
}

Money& Money::operator++() {
    ++hryvnia;
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    ++kopiyky;
    if (kopiyky == 100) {
        ++hryvnia;
        kopiyky = 0;
    }
    return temp;
}

Money& Money::operator--() {
    --hryvnia;
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    if (kopiyky == 0) {
        --hryvnia;
        kopiyky = 99;
    } else {
        --kopiyky;
    }
    return temp;
}