#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include "Book.h"
#include "Member.h"

using namespace std;

class Library
{
private:
    Book* books;
    Member* members;

    int bookCount;
    int memberCount;

    int maxBooks;
    int maxMembers;

public:

    Library(int booksNumber, int membersNumber)
    {
        maxBooks = booksNumber;
        maxMembers = membersNumber;

        bookCount = 0;
        memberCount = 0;

        books = new Book[maxBooks];
        members = new Member[maxMembers];
    }

    ~Library()
    {
        delete[] books;
        delete[] members;
    }

    void addBook(Book b)
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

        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getBookID() == b.getBookID())
            {
                cout << "Book ID already exists!" << endl;
                return;
            }
        }

        if (bookCount < maxBooks)
        {
            books[bookCount] = b;
            bookCount++;

            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Library is full!" << endl;
        }
    }

    void addMember(Member m)
    {
        if (m.getMemberID() <= 0)
        {
            cout << "Member ID must be greater than 0!" << endl;
            return;
        }

        for (int i = 0; i < memberCount; i++)
        {
            if (members[i].getMemberID() == m.getMemberID())
            {
                cout << "Member ID already exists!" << endl;
                return;
            }
        }

        if (memberCount < maxMembers)
        {
            members[memberCount] = m;
            memberCount++;

            cout << "Member added successfully!" << endl;
        }
        else
        {
            cout << "Members list is full!" << endl;
        }
    }

    void displayAllBooks()
    {
        if (bookCount == 0)
        {
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < bookCount; i++)
        {
            books[i].displayBook();
        }
    }

    void displayAllMembers()
    {
        if (memberCount == 0)
        {
            cout << "No members available." << endl;
            return;
        }

        for (int i = 0; i < memberCount; i++)
        {
            members[i].displayMember();
        }
    }

    void searchBook(int id)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i].getBookID() == id)
            {
                books[i].displayBook();
                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    void searchMember(int id)
    {
        for (int i = 0; i < memberCount; i++)
        {
            if (members[i].getMemberID() == id)
            {
                members[i].displayMember();
                return;
            }
        }

        cout << "Member not found!" << endl;
    }

    void borrowBook(int bookID, int memberID)
    {
        bool memberFound = false;

        for (int i = 0; i < memberCount; i++)
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

        for (int i = 0; i < bookCount; i++)
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
        for (int i = 0; i < bookCount; i++)
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

    void displayBorrowedBooks()
    {
        bool found = false;

        for (int i = 0; i < bookCount; i++)
        {
            if (!books[i].getAvailable())
            {
                books[i].displayBook();
                found = true;
            }
        }

        if (!found)
        {
            cout << "No books are currently borrowed." << endl;
        }
    }
};

#endif
