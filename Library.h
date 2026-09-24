#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>

#include "Book.h"
#include "Member.h"
#include "FinanceManger.h"

using namespace std;

class Library
{
private:
    vector<Book> books;
    vector<Member> members;
    FinanceManager financeManager;

    int maxBooks;
    int maxMembers;

    const double membershipFee = 100;

    void displayBook(const Book& book) const
    {
        cout << "Book ID: " << book.getBookID() << endl;
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "Category: " << book.getCategory() << endl;
        cout << "Price: " << book.getPrice() << endl;

        if (book.getAvailable())
        {
            cout << "Available: Yes" << endl;
        }
        else
        {
            cout << "Available: No" << endl;
            cout << "Borrowed By Member ID: "
                 << book.getBorrowedBy() << endl;
        }

        cout << "------------------------" << endl;
    }

    void displayMember(const Member& member) const
    {
        cout << "Member ID: " << member.getMemberID() << endl;
        cout << "Name: " << member.getName() << endl;
        cout << "Phone: " << member.getPhone() << endl;
        cout << "Email: " << member.getEmail() << endl;
        cout << "------------------------" << endl;
    }

public:

    Library(int booksNumber, int membersNumber, int transactionsNumber)
        : financeManager(transactionsNumber),
          maxBooks(booksNumber),
          maxMembers(membersNumber)
    {
        if (maxBooks <= 0)
        {
            maxBooks = 1;
        }

        if (maxMembers <= 0)
        {
            maxMembers = 1;
        }
    }

    void addBook(const Book& b)
    {
        if (b.getBookID() <= 0)
        {
            cout << "Book ID must be greater than 0!" << endl;
            return;
        }

        if (b.getPrice() <= 0)
        {
            cout << "Book price must be greater than 0!" << endl;
            return;
        }

        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getBookID() == b.getBookID())
            {
                cout << "Book ID already exists!" << endl;
                return;
            }
        }

        if ((int)books.size() >= maxBooks)
        {
            cout << "Library is full!" << endl;
            return;
        }

        if (financeManager.recordExpense("Book Purchase", b.getPrice()))
        {
            books.push_back(b);

            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Book was not added because the finance transaction could not be recorded!" << endl;
        }
    }

    void addMember(const Member& m)
    {
        if (m.getMemberID() <= 0)
        {
            cout << "Member ID must be greater than 0!" << endl;
            return;
        }

        for (int i = 0; i < (int)members.size(); i++)
        {
            if (members[i].getMemberID() == m.getMemberID())
            {
                cout << "Member ID already exists!" << endl;
                return;
            }
        }

        if ((int)members.size() >= maxMembers)
        {
            cout << "Members list is full!" << endl;
            return;
        }

        if (financeManager.recordIncome("Membership Fee", membershipFee))
        {
            members.push_back(m);

            cout << "Member added successfully!" << endl;
        }
        else
        {
            cout << "Member was not added because the finance transaction could not be recorded!" << endl;
        }
    }

    void displayAllBooks() const
    {
        if (books.empty())
        {
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < (int)books.size(); i++)
        {
            displayBook(books[i]);
        }
    }

    void displayAllMembers() const
    {
        if (members.empty())
        {
            cout << "No members available." << endl;
            return;
        }

        for (int i = 0; i < (int)members.size(); i++)
        {
            displayMember(members[i]);
        }
    }

    void searchBook(int id) const
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getBookID() == id)
            {
                displayBook(books[i]);
                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    void searchMember(int id) const
    {
        for (int i = 0; i < (int)members.size(); i++)
        {
            if (members[i].getMemberID() == id)
            {
                displayMember(members[i]);
                return;
            }
        }

        cout << "Member not found!" << endl;
    }

    void borrowBook(int bookID, int memberID)
    {
        bool memberFound = false;

        for (int i = 0; i < (int)members.size(); i++)
        {
            if (members[i].getMemberID() == memberID)
            {
                memberFound = true;
                break;
            }
        }

        if (!memberFound)
        {
            cout << "Member not found!" << endl;
            return;
        }

        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getBookID() == bookID)
            {
                if (books[i].getAvailable())
                {
                    books[i].setAvailable(false);
                    books[i].setBorrowedBy(memberID);

                    cout << "Book borrowed successfully!" << endl;
                }
                else
                {
                    cout << "Book is already borrowed!" << endl;
                }

                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    void returnBook(int bookID)
    {
        for (int i = 0; i < (int)books.size(); i++)
        {
            if (books[i].getBookID() == bookID)
            {
                if (!books[i].getAvailable())
                {
                    books[i].setAvailable(true);
                    books[i].setBorrowedBy(0);

                    cout << "Book returned successfully!" << endl;
                }
                else
                {
                    cout << "Book is already available!" << endl;
                }

                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    void displayBorrowedBooks() const
    {
        bool found = false;

        for (int i = 0; i < (int)books.size(); i++)
        {
            if (!books[i].getAvailable())
            {
                displayBook(books[i]);
                found = true;
            }
        }

        if (!found)
        {
            cout << "No books are currently borrowed." << endl;
        }
    }

    void displayAllTransactions() const
    {
        const vector<Transaction>& transactions =
            financeManager.getTransactions();

        if (transactions.empty())
        {
            cout << "No transactions found." << endl;
            return;
        }

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            cout << "Transaction ID: "
                 << transactions[i].getTransactionID() << endl;

            cout << "Type: "
                 << transactions[i].getType() << endl;

            cout << "Description: "
                 << transactions[i].getDescription() << endl;

            cout << "Amount: "
                 << transactions[i].getAmount() << endl;

            cout << "-----------------------------" << endl;
        }
    }

    void displayIncomeOnly() const
    {
        const vector<Transaction>& transactions =
            financeManager.getTransactions();

        bool found = false;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Income")
            {
                cout << "Transaction ID: "
                     << transactions[i].getTransactionID() << endl;

                cout << "Type: "
                     << transactions[i].getType() << endl;

                cout << "Description: "
                     << transactions[i].getDescription() << endl;

                cout << "Amount: "
                     << transactions[i].getAmount() << endl;

                cout << "-----------------------------" << endl;

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
        const vector<Transaction>& transactions =
            financeManager.getTransactions();

        bool found = false;

        for (int i = 0; i < (int)transactions.size(); i++)
        {
            if (transactions[i].getType() == "Expense")
            {
                cout << "Transaction ID: "
                     << transactions[i].getTransactionID() << endl;

                cout << "Type: "
                     << transactions[i].getType() << endl;

                cout << "Description: "
                     << transactions[i].getDescription() << endl;

                cout << "Amount: "
                     << transactions[i].getAmount() << endl;

                cout << "-----------------------------" << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "No expense transactions found." << endl;
        }
    }

    void showCurrentBalance() const
    {
        cout << "Current Balance: "
             << financeManager.getBalance() << endl;
    }

    void generateFinancialReport() const
    {
        double totalIncome = financeManager.getTotalIncome();
        double totalExpenses = financeManager.getTotalExpenses();
        double balance = financeManager.getBalance();

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