#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Bank;
class Account
{
private:
    string name;
    int balance;
public:
    string get_name()
    {
    return this->name;
    }
    int get_balance()
    {
    return this->balance;
    }
    friend Bank;
};

class Bank
{
private:
    vector<Account> account;
public:
    void add_account(string name, int balance)
    {
        Account new_account;
        new_account.name = name;
        new_account.balance = balance;

        this->account.push_back(new_account);
    }
    void get_account(string name)
    {
        int index = -1;
        for(int i = 0; i < this->account.size(); i++)
        {
            if(!name.compare(this->account[i].name))
            {
                index = i;
                break;
            }
        }
        if(index != -1)
        {
            cout << "Name: " << this->account[index].name << endl;
            cout << "Balance: " << this->account[index].balance << endl;
        }else {
            cout << "Not found " << endl;
        }
    }
};
int main()
{
    Bank bank;

    bank.add_account("Duc", 2000);
    bank.add_account("Giang", 10000);

    bank.get_account("Duc");

    return 0;
}