#include <iostream>
#include <
using namespace std;

class bankAcc
{
private:
    int accNumber;
    float balance = 50.00;

public:
    bankAcc(int accNo, float balance)
    {
        this->accNumber = accNo;
        this->balance = balance;
    }

    void deposit(float amount)
    {
        balance += amount;
        cout << "Money Deposited to savings account\n";
    }

    void withdraw(float amount)
    {
        if (amount > balance)
        {
            cout << "Not enough Balance\n";
        }
        else
        {
            balance -= amount;
        }
    }

    void getBalance()
    {
        cout << "Total Balance: " << balance << endl;
    }
};

int main()
{

    bankAcc acc1(45943, 50);

    acc1.deposit(500.69);
    acc1.getBalance();
    acc1.withdraw(84000.69);

    return 0;
}