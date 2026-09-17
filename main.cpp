#include <iostream>
#include <string>
#include <limits>

#include "Book.h"
#include "Member.h"
#include "Library.h"

using namespace std;

int main()
{
    int maxBooks;
    int maxMembers;

    cout << "==================================" << endl;
    cout << "     Library Management System" << endl;
    cout << "==================================" << endl;

    // Get maximum number of books
    cout << "Enter maximum number of books: ";
    cin >> maxBooks;

    while (cin.fail() || maxBooks <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid number! Enter max books again: ";
        cin >> maxBooks;
    }

    // Get maximum number of members
    cout << "Enter maximum number of members: ";
    cin >> maxMembers;

    while (cin.fail() || maxMembers <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid number! Enter max members again: ";
        cin >> maxMembers;
    }

    Library library(maxBooks, maxMembers);

    int choice;

    do
    {
        cout << endl;
        cout << "==================================" << endl;
        cout << "     Library Management System" << endl;
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
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input! Please enter a number: ";
            cin >> choice;
        }

        if (choice == 1)
        {
            int id;
            string title;
            string author;
            string category;
            double price;

            cout << "Enter Book ID: ";
            cin >> id;

            while (cin.fail() || id <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Invalid Book ID! Please enter a positive number: ";
                cin >> id;
            }

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            cout << "Enter Category: ";
            getline(cin, category);

            cout << "Enter Price: ";
            cin >> price;

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
            cin >> id;

            cin.ignore();

            cout << "Enter Member Name: ";
            getline(cin, name);

            cout << "Enter Phone: ";
            getline(cin, phone);

            cout << "Enter Email: ";
            getline(cin, email);

            Member member(id, name, phone, email);

            library.addMember(member);
        }

        else if (choice == 3)
        {
            cout << endl;
            cout << "===== All Books =====" << endl;

            library.displayAllBooks();
        }

        else if (choice == 4)
        {
            cout << endl;
            cout << "===== All Members =====" << endl;

            library.displayAllMembers();
        }

        else if (choice == 5)
        {
            int id;

            cout << "Enter Book ID: ";
            cin >> id;

            library.searchBook(id);
        }

        else if (choice == 6)
        {
            int id;

            cout << "Enter Member ID: ";
            cin >> id;

            library.searchMember(id);
        }

        else if (choice == 7)
        {
            int bookID;
            int memberID;

            cout << "Enter Book ID: ";
            cin >> bookID;

            cout << "Enter Member ID: ";
            cin >> memberID;

            library.borrowBook(bookID, memberID);
        }

        else if (choice == 8)
        {
            int bookID;

            cout << "Enter Book ID: ";
            cin >> bookID;

            library.returnBook(bookID);
        }

        else if (choice == 9)
        {
            cout << endl;
            cout << "===== Borrowed Books =====" << endl;

            library.displayBorrowedBooks();
        }

        else if (choice == 0)
        {
            cout << endl;
            cout << "Thank you for using Library Management System!" << endl;
        }

        else
        {
            cout << "Invalid choice! Please try again." << endl;
        }

    }
    while (choice != 0);

    return 0;
}
