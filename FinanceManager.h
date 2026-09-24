#ifndef FINANCE_MANAGER_H
#define FINANCE_MANAGER_H

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

    const vector<Transaction>& getTransactions() const
    {
        return transactions;
    }

    double getTotalIncome() const
    {
        double totalIncome = 0;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Income")
            {
                totalIncome += transactions[i].getAmount();
            }
        }

        return totalIncome;
    }

    double getTotalExpenses() const
    {
        double totalExpenses = 0;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Expense")
            {
                totalExpenses += transactions[i].getAmount();
            }
        }

        return totalExpenses;
    }
};

#endif
