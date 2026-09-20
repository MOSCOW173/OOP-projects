#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

#include <iostream>
#include <string>

#include "Transaction.h"

using namespace std;

class FinanceManager
{
private:
    Transaction* transactions;
    int transactionCount;
    int maxTransactions;
    double balance;

public:
    FinanceManager(int maxNumberOfTransactions)
    {
        maxTransactions = maxNumberOfTransactions;
        transactionCount = 0;
        balance = 0;

        transactions = new Transaction[maxTransactions];
    }

    ~FinanceManager()
    {
        delete[] transactions;
    }

    void recordIncome(string description, double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid income amount!" << endl;
            return;
        }

        if (description.empty())
        {
            cout << "Description cannot be empty!" << endl;
            return;
        }

        if (transactionCount >= maxTransactions)
        {
            cout << "Error: Maximum capacity reached! Cannot add more transactions." << endl;
            return;
        }

        int transactionID = transactionCount + 1;

        transactions[transactionCount] =
            Transaction(transactionID, "Income", description, amount);

        transactionCount++;
        balance += amount;

        cout << "Income recorded successfully." << endl;
    }

    void recordExpense(string description, double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid expense amount!" << endl;
            return;
        }

        if (description.empty())
        {
            cout << "Description cannot be empty!" << endl;
            return;
        }

        if (transactionCount >= maxTransactions)
        {
            cout << "Error: Maximum capacity reached! Cannot add more transactions." << endl;
            return;
        }

        int transactionID = transactionCount + 1;

        transactions[transactionCount] =
            Transaction(transactionID, "Expense", description, amount);

        transactionCount++;
        balance -= amount;

        cout << "Expense recorded successfully." << endl;
    }

    double getBalance()
    {
        return balance;
    }

    void displayAllTransactions()
    {
        if (transactionCount == 0)
        {
            cout << "No transactions found." << endl;
            return;
        }

        for (int i = 0; i < transactionCount; i++)
        {
            transactions[i].displayTransaction();
        }
    }

    void displayIncomeOnly()
    {
        bool found = false;

        for (int i = 0; i < transactionCount; i++)
        {
            if (transactions[i].getType() == "Income")
            {
                transactions[i].displayTransaction();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No income transactions found." << endl;
        }
    }

    void displayExpensesOnly()
    {
        bool found = false;

        for (int i = 0; i < transactionCount; i++)
        {
            if (transactions[i].getType() == "Expense")
            {
                transactions[i].displayTransaction();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No expense transactions found." << endl;
        }
    }

    void generateFinancialReport()
    {
        double totalIncome = 0;
        double totalExpenses = 0;

        for (int i = 0; i < transactionCount; i++)
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
