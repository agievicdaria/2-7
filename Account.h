#pragma once
#include "Money.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Account {
private:
    string ownerLastName;
    string accountNumber;
    double interestRate;
    Money balance;

public:
    Account();
    Account(const string& ownerLastName, const string& accountNumber, double interestRate, const Money& balance);

    const string& GetOwnerLastName() const { return ownerLastName; }
    const string& GetAccountNumber() const { return accountNumber; }
    double GetInterestRate() const { return interestRate; }
    const Money& GetBalance() const { return balance; }
    
    void Withdraw(const Money& amount);
    void Deposit(const Money& amount);
    void AddInterest();
    void ChangeOwner(const string& newOwnerLastName);
    void ConvertToDollars();
    void ConvertToEuros();
    void ConvertToHryvnya();
    string AmountInWords() const;
    string ToString() const;

    // Account operator-(const Money& amount) const;
    // Account operator+(const Money& amount) const;
    // Account operator+(double interestRate) const;

    friend istream& operator>>(istream& in, Account& account);
    friend ostream& operator<<(ostream& out, const Account& account);
};
