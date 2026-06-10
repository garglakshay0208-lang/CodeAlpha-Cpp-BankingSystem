// •Design classes for Customer, Account and Transaction with necessary attributes.
// ● Implement functions to create and manage customers and accounts.
// ● Include features for deposits, withdrawals and fund transfers.
// ● Store transaction history and allow users to view recent transactions.
// ● Display account information like balance and transaction details to customers.


#include <iostream>
#include <vector>
using namespace std;

class Transaction {
    string type;
    double amount;
    string date;
    public:
    Transaction(string type, double amount, string date) {
        this->type = type;
        this->amount = amount;
        this->date = date;
    }
    void display() const{
        cout << "Type: " << type << ", Amount: $" << amount << ", Date: " << date << endl;
    }
};

class Account {
    int accountNumber;
    double balance;
    vector<Transaction>transactions;
    public:
    Account(int accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    int getAccountNumber() {
        return accountNumber;
    }
    double getBalance() {
        return balance;
    }
    void deposit(double amount, string Date) {
        balance += amount;
        // Add transaction to history
        transactions.push_back(Transaction("Deposit", amount, Date));
    }
    void withdraw(double amount, string Date) {
        if (amount <= balance) {
            balance -= amount;
            // Add transaction to history
            transactions.push_back(Transaction("Withdrawal", amount, Date));
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
    bool transfer(Account &toAccount, double amount, string Date) {
        if (amount <= balance) {
            balance -= amount;
            toAccount.deposit(amount, Date);
            // Add transaction to history
            transactions.push_back(Transaction("Transfer", amount, Date));
            return true;
        } else {
            cout << "Insufficient funds for transfer!" << endl;
            return false;
        }
    }

    void showTransactionHistory() {
        cout << "Transaction History for Account " << accountNumber << ":" << endl;
        for (const auto &transaction : transactions){
            transaction.display();
        }
    }
    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Customer {
    string name;
    int customerID;
    string address;
    Account account_number;
    public:
    Customer(string name, int customerID, string address, Account account_number) : account_number(account_number) {
        this->name = name;
        this->customerID = customerID;
        this->address = address;
    }
    Account& getAccount() {
        return account_number;
    }
    void display_customer_details() {
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Address: " << address << endl;
    }
};


int main(){
    Customer c1("Lckky", 1, "123 Dehli Main St", Account(1001, 0.0));
    Customer c2("Harshdeep Sing", 2, "456 Punjab Amritsar mall road ", Account(1002, 0.0));

    c1.getAccount().deposit(5000.0, "2026-06-01");
    c1.getAccount().withdraw(2000.0, "2026-06-02");
    c1.getAccount().transfer(c2.getAccount(), 1000.0, "2026-06-03");
    c1.getAccount().showTransactionHistory();
    cout<<"Customer 2 details";
    c2.display_customer_details();
    c2.getAccount().showTransactionHistory();
    return 0;
}