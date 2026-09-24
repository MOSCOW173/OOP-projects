#include <iostream>
#include <string>
#include <limits>

#include "Book.h"
#include "Member.h"
#include "Library.h"

using namespace std;

// Read integer
int readInt()
{
    int value;

    while (true)
    {
        if (cin >> value)
        {
            return value;
        }

        if (cin.eof())
        {
            return 0;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input! Please enter a number: ";
    }
}

// Read positive integer
int readPositiveInt()
{
    int value;

    while (true)
    {
        value = readInt();

        if (cin.eof())
        {
            return 0;
        }

        if (value > 0)
        {
            return value;
        }

        cout << "Please enter a positive number: ";
    }
}

// Read positive double
double readPositiveDouble()
{
    double value;

    while (true)
    {
        if (cin >> value && value > 0)
        {
            return value;
        }

        if (cin.eof())
        {
            return 0;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a positive number: ";
    }
}

// Read non-empty string
string readNonEmptyString()
{
    string value;

    while (true)
    {
        if (!getline(cin, value))
        {
            return "";
        }

        if (!value.empty() &&
            value.find_first_not_of(' ') != string::npos)
        {
            return value;
        }

        cout << "Input cannot be empty! Please enter again: ";
    }
}

// Read phone number
string readPhone()
{
    string phone;

    while (true)
    {
        if (!getline(cin, phone))
        {
            return "";
        }

        if (phone.empty())
        {
            cout << "Phone cannot be empty! Please enter again: ";
            continue;
        }

        bool valid = true;

        for (int i = 0; i < (int)phone.length(); i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            return phone;
        }

        cout << "Invalid phone! Please enter numbers only: ";
    }
}

// Read email
string readEmail()
{
    string email;

    while (true)
    {
        if (!getline(cin, email))
        {
            return "";
        }

        size_t atPosition = email.find('@');

        if (!email.empty() &&
            atPosition != string::npos &&
            email.find('.', atPosition + 1) != string::npos)
        {
            return email;
        }

        cout << "Invalid email! Please enter a valid email: ";
    }
}

int main()
{
    int maxBooks;
    int maxMembers;
    int maxTransactions;

    cout << "==================================" << endl;
    cout << "     Library Management System" << endl;
    cout << "==================================" << endl;

    cout << "Enter maximum number of books: ";
    maxBooks = readPositiveInt();

    if (cin.eof())
    {
        return 0;
    }

    cout << "Enter maximum number of members: ";
    maxMembers = readPositiveInt();

    if (cin.eof())
    {
        return 0;
    }

    cout << "Enter maximum number of transactions: ";
    maxTransactions = readPositiveInt();

    if (cin.eof())
    {
        return 0;
    }

    Library library(maxBooks, maxMembers, maxTransactions);

    int choice;

    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "             Main Menu" << endl;
        cout << "==================================" << endl;

        cout << "1. Add Book" << endl;
        cout << "2. Add Member" << endl;
        cout << "3. Display All Books" << endl;
        cout << "4. Display All Members" << endl;
        cout << "5. Search Book" << endl;
        cout << "6. Search Member" << endl;
        cout << "7. Borrow Book" << endl;
        cout << "8. Return Book" << endl;
        cout << "9. Display Borrowed Books" << endl;
        cout << "10. Finance Management" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        choice = readInt();

        if (cin.eof())
        {
            break;
        }

        while (choice < 0 || choice > 10)
        {
            cout << "Invalid choice! Please enter a number from 0 to 10: ";
            choice = readInt();

            if (cin.eof())
            {
                break;
            }
        }

        if (cin.eof())
        {
            break;
        }

        if (choice == 1)
        {
            int id;
            string title;
            string author;
            string category;
            double price;

            cout << "Enter Book ID: ";
            id = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Title: ";
            title = readNonEmptyString();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Author: ";
            author = readNonEmptyString();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Category: ";
            category = readNonEmptyString();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Price: ";
            price = readPositiveDouble();

            if (cin.eof())
            {
                break;
            }

            Book book(id, title, author, category, price);

            library.addBook(book);
        }

        else if (choice == 2)
        {
            int id;
            string name;
            string phone;
            string email;

            cout << "Enter Member ID: ";
            id = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Member Name: ";
            name = readNonEmptyString();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Phone: ";
            phone = readPhone();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Email: ";
            email = readEmail();

            if (cin.eof())
            {
                break;
            }

            Member member(id, name, phone, email);

            library.addMember(member);
        }

        else if (choice == 3)
        {
            library.displayAllBooks();
        }

        else if (choice == 4)
        {
            library.displayAllMembers();
        }

        else if (choice == 5)
        {
            cout << "Enter Book ID: ";
            int id = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            library.searchBook(id);
        }

        else if (choice == 6)
        {
            cout << "Enter Member ID: ";
            int id = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            library.searchMember(id);
        }

        else if (choice == 7)
        {
            cout << "Enter Book ID: ";
            int bookID = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            cout << "Enter Member ID: ";
            int memberID = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            library.borrowBook(bookID, memberID);
        }

        else if (choice == 8)
        {
            cout << "Enter Book ID: ";
            int bookID = readPositiveInt();

            if (cin.eof())
            {
                break;
            }

            library.returnBook(bookID);
        }

        else if (choice == 9)
        {
            library.displayBorrowedBooks();
        }

        else if (choice == 10)
        {
            int financeChoice;

            do
            {
                cout << endl;
                cout << "==================================" << endl;
                cout << "        Finance Management" << endl;
                cout << "==================================" << endl;

                cout << "1. Display All Transactions" << endl;
                cout << "2. Display Income Only" << endl;
                cout << "3. Display Expenses Only" << endl;
                cout << "4. Show Current Balance" << endl;
                cout << "5. Generate Financial Report" << endl;
                cout << "0. Back to Main Menu" << endl;

                cout << "Enter your choice: ";
                financeChoice = readInt();

                if (cin.eof())
                {
                    break;
                }

                while (financeChoice < 0 || financeChoice > 5)
                {
                    cout << "Invalid choice! Please enter a number from 0 to 5: ";
                    financeChoice = readInt();

                    if (cin.eof())
                    {
                        break;
                    }
                }

                if (cin.eof())
                {
                    break;
                }

                if (financeChoice == 1)
                {
                    library.displayAllTransactions();
                }

                else if (financeChoice == 2)
                {
                    library.displayIncomeOnly();
                }

                else if (financeChoice == 3)
                {
                    library.displayExpensesOnly();
                }

                else if (financeChoice == 4)
                {
                    library.showCurrentBalance();
                }

                else if (financeChoice == 5)
                {
                    library.generateFinancialReport();
                }

            } while (financeChoice != 0 && !cin.eof());
        }

        else if (choice == 0)
        {
            cout << "Thank you for using Library Management System!" << endl;
        }

    } while (choice != 0 && !cin.eof());

    return 0;
}