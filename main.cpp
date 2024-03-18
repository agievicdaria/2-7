#include "Account.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
    Account account;

    cout << "Enter your information: " << endl;
    cin >> account;
    cout << account;

    // Money withdrawAmount(100, 50);
    // account = account - withdrawAmount;
    account.Withdraw(Money(200, 30));
    cout << account;

    // Money depositAmount(200, 75);
    // account = account + depositAmount;
    account.Deposit(Money(500, 25));
    cout << account;

    // double interestRate;
    // cout << "Enter interest rate to apply: ";
    // cin >> interestRate;
    // account = account + interestRate;

    // account = account + account.GetInterestRate();
    account.AddInterest();
    cout << account;

    account.ChangeOwner("Black");
    cout << account;

    account.ConvertToDollars();
    cout << "Balance in dollars: " << account.ToString() << endl;

    account.ConvertToEuros();
    cout << "Balance in euros: " << account.ToString() << endl;

    account.ConvertToHryvnya();
    cout << "Balance in hryvnia: " << account.ToString() << endl;

    cout << "Balance in words: " << account.AmountInWords() << endl;

    return 0;
}
