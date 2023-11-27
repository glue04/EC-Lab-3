#include <iostream>
#include <iomanip>
using namespace std;

class Account{
    public:
        //class members
        string accountNumber;
        string accountHolder;
        float balance;
};

class SavingsAccount : public Account{
    //additional members
    public:
        float interestRate;
        void deposit(int value){
            balance = balance + value;
        }

        void withdraw(int value){
            if (balance-value > 0)
                balance = balance - value;
            else
                cout << "Minimum value of 0 surpassed, declining transaction" << endl;
        }

        SavingsAccount(){
            accountNumber = "A000";
            accountHolder = "None";
            balance = 0;
            interestRate = 0;
        }

        SavingsAccount(string n, string h, float b, float i){
            accountNumber = n;
            accountHolder = h;
            balance = b;
            interestRate = i;
        }

        //the fact that 'friend' is actually something in C++ is hella funny to me
        friend ostream &operator<<( ostream &output, SavingsAccount &S){
            output << "Holder: " << S.accountHolder << "\nBalance: $" << S.balance << "\nInterest Rate: " << S.interestRate * 100.00 << "%\n";
            return output;
        }

        void displayDetails(){
            cout << "Account Details for Savings Account (ID:" << accountNumber << "):\n" << *this << endl;;
        }
    };

class CurrentAccount : public Account{
    //additional members
    public:
        float overdraftLimit;
        void deposit(int value){
            balance = balance + value;
        }

        void withdraw(int value){
            if (balance-value > overdraftLimit*-1)
                balance = balance - value;
            else
                cout << "Overdraft limit reached, declining transaction" << endl;
        }

        void displayDetails(){
            cout << "Account Details for Current Account (ID:" << accountNumber << "):\n" << *this << endl;
        }

        CurrentAccount(){
            accountNumber = "A000";
            accountHolder = "None";
            balance = 0;
            overdraftLimit = 0;
        }

        CurrentAccount(string n, string h, float b, float o){
            accountNumber = n;
            accountHolder = h;
            balance = b;
            overdraftLimit = o;
        }
        friend ostream &operator<<( ostream &output, CurrentAccount &C){
            output << "Holder: " << C.accountHolder << "\nBalance: $" << C.balance << "\nOverdraft Limit: $" << C.overdraftLimit << "\n" << endl;
            return output;
        }
};

int main() {

    //added for trailing 0's
    cout << fixed << setprecision(2);

    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    savings.deposit(500);
    current.withdraw(1000);

    //formatting
    cout << "Account details after deposit and withdrawal:\n" << endl;

    savings.displayDetails();
    current.displayDetails();

    
    //I can't figure out how to overload the '+' operator and get this part to work. Seeing as it 10:36pm and I'm hella hungry, I will be turning it in as is
    //I would absolutely love to see the solution to this, because I know with 95% certainty I could get this to work in Python, but C++, not so much
    //Besides that though the rest of the code works as it should, overdraft limits and everything. This lab was actually hella fun :)

    /*Transfer 300 from savings to current
    current = current + savings;

    savings.displayDetails();
    current.displayDetails();*/

    return 0;
};