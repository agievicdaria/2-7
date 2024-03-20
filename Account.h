#pragma once
#include "Money.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Account {
private:
    string ownerLastName;
    int accountNumber;
    double interestRate;
    Money balance;

public:
    Account();
    Account(const string& ownerLastName, int accountNumber, double interestRate, const Money& balance);
    Account(const Account& second);

    const string& GetOwnerLastName() const { return ownerLastName; }
    int GetAccountNumber() const { return accountNumber; }
    double GetInterestRate() const { return interestRate; }
    const Money& GetBalance() const { return balance; }
    void SetOwnerLastName(const string& value) { ownerLastName = value; }
    void SetAccountNumber(int value) { accountNumber = value; }
    void SetInterestRate(double value) { interestRate = value; }
    void SetBalance(const Money& value) { balance = value; }
    
    void Withdraw(const Money& amount);
    void Deposit(const Money& amount);
    void AddInterest();
    void ChangeOwner(const string& newOwnerLastName);
    void ConvertToDollars();
    void ConvertToEuros();
    void ConvertToHryvnya();
    string AmountInWords() const;
    operator string() const;

    Account& operator++();
    Account operator++(int);
    Account& operator--();
    Account operator--(int);
    Account& operator=(const Account& other);
    friend istream& operator>>(istream& in, Account& account);
    friend ostream& operator<<(ostream& out, const Account& account);
    // Account operator-(const Money& amount) const;
    // Account operator+(const Money& amount) const;
    // Account operator+(double interestRate) const;
};
