#include <iostream>
using namespace std;
class Account
{
private:
    string customerName;
    int accountNumber;
    string accountType;

public:
    void setAccountInfo()
    {
        cout << "\nEnter Customer Name: ";
        cin >> customerName;
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cout << "Enter Account Type: ";
        cin >> accountType;
    }

    void showAccountInfo()
    {
        cout << "\n\nCustomer Name: " << customerName;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Type: " << accountType;
    }
};

class CurrentAccount : public Account
{
private:
    float currentBalance;

public:
    void displayCurrentBalance()
    {
        cout << "\nBalance: " << currentBalance;
    }

    void addFunds()
    {
        float depositAmount;
        cout << "\nEnter amount to Deposit: ";
        cin >> depositAmount;
        currentBalance += depositAmount;
    }

    void withdrawFunds()
    {
        float withdrawalAmount;
        cout << "\n\nBalance: " << currentBalance;
        cout << "\nEnter amount to withdraw: ";
        cin >> withdrawalAmount;
        if (currentBalance > 1000)
        {
            currentBalance -= withdrawalAmount;
            cout << "\nBalance After Withdrawal: " << currentBalance;
        }
        else
        {
            cout << "\nInsufficient Balance";
        }
    }
};

class SavingsAccount : public Account
{
private:
    float savingsBalance;

public:
    void displaySavingsBalance()
    {
        cout << "\nBalance: " << savingsBalance;
    }

    void depositAmount()
    {
        float depositAmount, interest;
        cout << "\nEnter amount to Deposit: ";
        cin >> depositAmount;
        savingsBalance += depositAmount;
        interest = (savingsBalance * 2) / 100;
        savingsBalance += interest;
    }

    void withdrawAmount()
    {
        float withdrawalAmount;
        cout << "\nBalance: " << savingsBalance;
        cout << "\nEnter amount to withdraw: ";
        cin >> withdrawalAmount;
        if (savingsBalance > 500)
        {
            savingsBalance -= withdrawalAmount;
            cout << "\nBalance After Withdrawal: " << savingsBalance;
        }
        else
        {
            cout << "\nInsufficient Balance";
        }
    }
};

int main()
{
    CurrentAccount currentAcc;
    SavingsAccount savingsAcc;
    char accountType;
    cout << "\nEnter S for savings customer and C for current account customer: ";
    cin >> accountType;
    int choice;

    if (accountType == 's' || accountType == 'S')
    {
        savingsAcc.setAccountInfo();
        while (true)
        {
            cout << "\nChoose Your Option" << endl;
            cout << "1) Deposit" << endl;
            cout << "2) Withdraw" << endl;
            cout << "3) Display Balance" << endl;
            cout << "4) Display Full Details" << endl;
            cout << "5) Exit" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                savingsAcc.depositAmount();
                break;
            case 2:
                savingsAcc.withdrawAmount();
                break;
            case 3:
                savingsAcc.displaySavingsBalance();
                break;
            case 4:
                savingsAcc.showAccountInfo();
                savingsAcc.displaySavingsBalance();
                break;
            case 5:
                goto exitLoop;
            default:
                cout << "\n\nInvalid choice, please try again.";
            }
        }
    }
    else if (accountType == 'c' || accountType == 'C')
    {
        currentAcc.setAccountInfo();
        while (true)
        {
            cout << "\nChoose Your Option" << endl;
            cout << "1) Deposit" << endl;
            cout << "2) Withdraw" << endl;
            cout << "3) Display Balance" << endl;
            cout << "4) Display Full Details" << endl;
            cout << "5) Exit" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                currentAcc.addFunds();
                break;
            case 2:
                currentAcc.withdrawFunds();
                break;
            case 3:
                currentAcc.displayCurrentBalance();
                break;
            case 4:
                currentAcc.showAccountInfo();
                currentAcc.displayCurrentBalance();
                break;
            case 5:
                goto exitLoop;
            default:
                cout << "\n\nInvalid choice, please try again.";
            }
        }
    }
    else
    {
        cout << "\nInvalid Account Selection";
    }

exitLoop:
    cout << "\nThank you for banking with us!";
    return 0;
}
