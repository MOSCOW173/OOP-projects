#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
private:
    int transactionID;
    string type;
    string description;
    double amount;

public:

    Transaction()
        : transactionID(0), type(""), description(""), amount(0)
    {
    }

    Transaction(int id, const string& transactionType,
                const string& transactionDescription,
                double transactionAmount)
        : transactionID(id),
          type(transactionType),
          description(transactionDescription),
          amount(transactionAmount)
    {
    }

    int getTransactionID() const
    {
        return transactionID;
    }

    string getType() const
    {
        return type;
    }

    string getDescription() const
    {
        return description;
    }

    double getAmount() const
    {
        return amount;
    }

    void setTransactionID(int id)
    {
        transactionID = id;
    }

    void setType(const string& transactionType)
    {
        type = transactionType;
    }

    void setDescription(const string& transactionDescription)
    {
        description = transactionDescription;
    }

    void setAmount(double transactionAmount)
    {
        amount = transactionAmount;
    }
};

#endif