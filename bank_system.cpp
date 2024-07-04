#include <iostream>
#include <limits> 

using namespace std;

class Bank {
    char name[100], address[100], accountType;
    int balance;
public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

void Bank::open_account() {
    cout << "Enter your full name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(name, 100);
    cout << "Enter your address: ";
    cin.getline(address, 100);
    cout << "What type of account do you want to open, saving (s) or current (c)? ";
    cin >> accountType;
    cout << "Enter amount to deposit: ";
    cin >> balance;
    cout << "Your account has been created.\n";
}

void Bank::deposit_money() {
    int amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    balance += amount;
    cout << "Your new balance is " << balance << ".\n";
}

void Bank::withdraw_money() {
    int amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Insufficient balance!\n";
    } else {
        balance -= amount;
        cout << "You withdrew " << amount << ". Your new balance is " << balance << ".\n";
    }
}
