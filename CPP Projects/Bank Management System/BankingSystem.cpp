#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

// Creating user's bank account
class account_create
{
protected:
    int balance;
    string customer_name;
    string other_name;
    string customer_address;
    string res = "";
    string ifsc_code;
    string filename;
    long long account_number;
    long long cif_number;
    ofstream myfile;

public:
    void creation()
    {
        cout << "Enter the customer's name: ";
        cin.ignore();
        getline(cin, customer_name);
        cout << "Enter the father's name or spouse's name: ";
        getline(cin, other_name);
        account_number = rand() % 100000000000 + 10000000000;
        cif_number = rand() % 100000000000 + 10000000000;
        time_t timestamp;
        time(&timestamp);
        cout << "Enter the address of the customer: ";
        getline(cin, customer_address);
        char alphabet[MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        for (int i = 1; i < 9; i++)
        {
            res = res + alphabet[rand() % MAX];
        }
        ifsc_code = "CPP" + res;
        cout << "Enter your bank balance: ";
        cin >> balance;
        filename = customer_name + ".txt";
        myfile.open(filename);
        myfile << "CIF Number: " << cif_number << endl;
        myfile << "Account Number: " << account_number << endl;
        myfile << "Customer Name: " << customer_name << endl;
        myfile << "Father/Spouse name: " << other_name << endl;
        myfile << "Issue Date: " << ctime(&timestamp);
        myfile << "Address: " << customer_address << endl;
        myfile << "IFSC Code: " << ifsc_code << endl;
        myfile << "Balance: " << balance << endl;
        myfile << "Transaction History: " << endl;
        myfile.close();
        cout << "Your Bank Account has successfully been created.\n";
    }

    void update_balance(int new_balance)
    {
        balance = new_balance;
        ofstream fl(filename, ios::app);              // Open file in append mode
        fl << "Updated Balance: " << balance << endl; // Append new balance
        fl.close();
    }

    int get_balance() const
    {
        return balance;
    }

    string get_filename() const
    {
        return filename;
    }
};

class credit
{
public:
    void deposit(account_create &account)
    {
        int amount;
        cout << "How much amount do you want to deposit? ";
        cin >> amount;
        int new_balance = account.get_balance() + amount;
        account.update_balance(new_balance);
        cout << "Your total bank balance is " << new_balance << endl;
    }
};

class debit
{
public:
    void withdraw(account_create &account)
    {
        int amount;
        cout << "How much amount do you want to withdraw? ";
        cin >> amount;
        if (amount <= account.get_balance())
        {
            int new_balance = account.get_balance() - amount;
            account.update_balance(new_balance);
            cout << "Your total bank balance is " << new_balance << endl;
        }
        else
        {
            cout << "Your bank has insufficient balance." << endl;
        }
    }
};

class check
{
public:
    void view(const account_create &account)
    {
        ifstream f(account.get_filename());
        string line;
        while (getline(f, line))
        {
            cout << line << endl;
        }
        f.close();
    }
};

int main()
{
    account_create account;
    credit c;
    debit d;
    check ch;
    bool is_account_created = false;

    while (true)
    {
        cout << "Type 1 if you are a new user of the bank\nType 2 if you want to deposit money\nType 3 if you want to withdraw money\nType 4 if you want to check your bank details\nType 0 to exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            account.creation();
            is_account_created = true;
        }
        else if (choice == 2)
        {
            if (is_account_created)
            {
                c.deposit(account);
            }
            else
            {
                cout << "Please create an account first." << endl;
            }
        }
        else if (choice == 3)
        {
            if (is_account_created)
            {
                d.withdraw(account);
            }
            else
            {
                cout << "Please create an account first." << endl;
            }
        }
        else if (choice == 4)
        {
            if (is_account_created)
            {
                ch.view(account);
            }
            else
            {
                cout << "Please create an account first." << endl;
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
