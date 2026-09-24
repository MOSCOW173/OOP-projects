#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include "Transaction.h"

using namespace std;

class FinanceManager
{
private:
    vector<Transaction> transactions;
    int maxTransactions;
    double balance;

    void displayTransaction(const Transaction& transaction) const
    {
        cout << "Transaction ID: "
             << transaction.getTransactionID() << endl;

        cout << "Type: "
             << transaction.getType() << endl;

        cout << "Description: "
             << transaction.getDescription() << endl;

        cout << "Amount: "
             << transaction.getAmount() << endl;

        cout << "-----------------------------" << endl;
    }

public:

    FinanceManager(int maxNumberOfTransactions)
        : maxTransactions(maxNumberOfTransactions), balance(0)
    {
        if (maxTransactions <= 0)
        {
            maxTransactions = 1;
        }
    }

    bool recordIncome(const string& description, double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        if (description.empty())
        {
            return false;
        }

        if ((int)transactions.size() >= maxTransactions)
        {
            return false;
        }

        int transactionID = (int)transactions.size() + 1;

        Transaction transaction(
            transactionID,
            "Income",
            description,
            amount
        );

        transactions.push_back(transaction);

        balance += amount;

        return true;
    }

    bool recordExpense(const string& description, double amount)
    {
        if (amount <= 0)
        {
            return false;
        }

        if (description.empty())
        {
            return false;
        }

        if ((int)transactions.size() >= maxTransactions)
        {
            return false;
        }

        int transactionID = (int)transactions.size() + 1;

        Transaction transaction(
            transactionID,
            "Expense",
            description,
            amount
        );

        transactions.push_back(transaction);

        balance -= amount;

        return true;
    }

    double getBalance() const
    {
        return balance;
    }

    void displayAllTransactions() const
    {
        if (transactions.empty())
        {
            cout << "No transactions found." << endl;
            return;
        }

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            displayTransaction(transactions[i]);
        }
    }

    void displayIncomeOnly() const
    {
        bool found = false;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Income")
            {
                displayTransaction(transactions[i]);
                found = true;
            }
        }

        if (!found)
        {
            cout << "No income transactions found." << endl;
        }
    }

    void displayExpensesOnly() const
    {
        bool found = false;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Expense")
            {
                displayTransaction(transactions[i]);
                found = true;
            }
        }

        if (!found)
        {
            cout << "No expense transactions found." << endl;
        }
    }

    void generateFinancialReport() const
    {
        double totalIncome = 0;
        double totalExpenses = 0;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Income")
            {
                totalIncome += transactions[i].getAmount();
            }
            else if (transactions[i].getType() == "Expense")
            {
                totalExpenses += transactions[i].getAmount();
            }
        }

        cout << endl;
        cout << "==================================" << endl;
        cout << "       Financial Report" << endl;
        cout << "==================================" << endl;
        cout << "Total Income: " << totalIncome << endl;
        cout << "Total Expenses: " << totalExpenses << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "==================================" << endl;
    }
};

#endif
