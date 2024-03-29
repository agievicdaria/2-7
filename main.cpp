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

    account.Withdraw(Money(200, 30));
    cout << account;

    account.Deposit(Money(500, 25));
    cout << account;

    account.AddInterest();
    cout << account;

    account.ChangeOwner("Black");
    cout << account;

    account.ConvertToDollars();
    cout << "Balance in dollars: " << account << endl;

    account.ConvertToEuros();
    cout << "Balance in euros: " << account << endl;

    account.ConvertToHryvnya();
    cout << "Balance in hryvnia: " << account << endl;

    cout << "Balance in words: " << account.AmountInWords() << endl;
    
    ++account;
    cout << "After prefix increment: " << account << endl;

    account++;
    cout << "Account after postfix increment: " << account << endl;

    --account;
    cout << "After prefix decrement: " << account << endl;

    account--;
    cout << "Account after postfix decrement: " << account << endl;


    Money money1(1000, 50);
    ++money1;
    cout << "After prefix increment: " << money1 << endl;

    money1++;
    cout << "Money1 after postfix increment: " << money1 << endl;

    --money1;
    cout << "After prefix decrement: " << money1 << endl;

    money1--;
    cout << "Money1 after postfix decrement: " << money1 << endl;

    Money money2(200, 30);

    cout << "Size of Account without #pragma pack(1): " << sizeof(Account) << endl;

    #pragma pack(1)
    cout << "Size of Account with #pragma pack(1): " << sizeof(Account) << endl;
    #pragma pack()

    cout << "Size of Money without #pragma pack(1): " << sizeof(Money) << endl;

    #pragma pack(1)
    cout << "Size of Money with #pragma pack(1): " << sizeof(Money) << endl;
    #pragma pack()
    return 0;
}
