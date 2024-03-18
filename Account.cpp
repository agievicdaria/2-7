#include "Account.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Account::Account() {
    ownerLastName = "";
    accountNumber = "";
    interestRate = 0.0;
    balance = Money();
}

Account::Account(const string& ownerLastName, const string& accountNumber, double interestRate, const Money& balance) {
    this->ownerLastName = ownerLastName;
    this->accountNumber = accountNumber;
    this->interestRate = interestRate;
    this->balance = balance;
}

istream& operator>>(istream& in, Account& account) {
    cout << "Enter owner's last name: ";
    in >> account.ownerLastName;

    cout << "Enter account number: ";
    in >> account.accountNumber;

    cout << "Enter interest rate: ";
    in >> account.interestRate;

    cout << "Enter balance (in hryvnia and kopiyky): ";
    in >> account.balance;

    return in;
}

ostream& operator<<(ostream& out, const Account& account) {
    out << "Owner: " << account.ownerLastName << endl;
    out << "Account Number: " << account.accountNumber << endl;
    out << "Interest Rate: " << account.interestRate << endl;
    out << "Balance: " << account.balance.GetHryvnia() << "," << static_cast<int>(account.balance.GetKopiyky()) << endl;

    return out;
}

void Account::ChangeOwner(const string& newOwnerLastName) {
    ownerLastName = newOwnerLastName;
}

void Account::ConvertToDollars() {
    double exchangeRate = 0.026;
    balance = balance * exchangeRate;
}

void Account::ConvertToEuros() {
    double exchangeRate = 0.91;
    balance = balance * exchangeRate;
}

void Account::ConvertToHryvnya() {
    double exchangeRate = 42.38;
    balance = balance * exchangeRate;
}

string Account::AmountInWords() const {
    const string _thousands[10] = { "", "tysyacha", "dvi tysiachy", "try tysiachy", "4otyry tysiachy", "p’jat tysiach", "6ist tysiach", "sim tysiach", "visim tysiach", "dev’jat tysiach" };
    const string _centuries[10] = { "", "sto", "dvisti", "trysta", "4onyrysta", "p’jatsot", "6istsot", "simsot", "visimsot", "dev’jatsot" };
    const string _decades[10] = { "", "", "dvadciat’", "trydciat’", "sorok", "p’jatdesiat", "6istdesiat", "simdesiat", "visimdesiat", "dev’janosto" };
    const string _digits[20] = { "", "odyn", "dva", "try", "4otyry", "p’jat’", "6ist’", "sim", "visim", "dev’jat’", "desiat’", "odynadciad’", "dvanadciad’", "trynadciad’", "4otyrnadciad’", "p’jatnadciad’", "6istnadciad’", "simnadciad’", "visimnadciad’", "dev’jatnadciad’" };

    long absBalance = abs(balance.GetHryvnia());
    int thousands = absBalance / 1000;
    absBalance %= 1000;
    int cen = absBalance / 100;
    absBalance %= 100;
    int dec = absBalance / 10;
    int dig = absBalance % 10;

    string amountInWords = "";
    if (thousands > 0)
        amountInWords += _thousands[thousands] + " ";

    amountInWords += _centuries[cen] + " " + _decades[dec] + " " + _digits[dig];

    amountInWords += " hryvnia " + to_string(balance.GetKopiyky()) + " kopiyok";

    return amountInWords;
}

string Account::ToString() const {
    stringstream sout;
    sout << balance.GetHryvnia() << "," << static_cast<int>(balance.GetKopiyky());
    return sout.str();
}

void Account::Withdraw(const Money& amount) {
    if (balance > amount) {
        balance = balance - amount;
        cout << "Withdrawal successful." << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void Account::Deposit(const Money& amount) {
    balance = balance + amount;
    cout << "Deposit successful." << endl;
}

void Account::AddInterest() {
    Money interest = balance * interestRate;
    balance = balance + interest;
}

// Account Account::operator-(const Money& amount) const {
//     Account newAccount(*this);
//     if (newAccount.balance > amount) {
//         newAccount.balance = newAccount.balance - amount;
//         cout << "Withdrawal successful." << endl;
//     } else {
//         cout << "Insufficient funds." << endl;
//     }
//     return newAccount;
// }

// Account Account::operator+(const Money& amount) const {
//     Account newAccount(*this);
//     newAccount.balance = newAccount.balance + amount;
//     cout << "Deposit successful." << endl;
//     return newAccount;
// }

// Account Account::operator+(double interestRate) const {
//     Account newAccount(*this);
//     Money interest = newAccount.balance * interestRate;
//     newAccount.balance = newAccount.balance + interest;
//     return newAccount;
// }

// Account Account::operator+(const Account& account, double additionalInterest) {
//     Account result = account;
//     result.interestRate += additionalInterest;
//     return result;
// }
