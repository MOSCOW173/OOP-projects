#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    int bookID;
    string title;
    string author;
    string category;
    double price;
    bool available;
    int borrowedBy;

public:

    Book()
    {
        bookID = 0;
        title = "";
        author = "";
        category = "";
        price = 0;
        available = true;
        borrowedBy = 0;
    }

    Book(int bookID, string title, string author, string category, double price)
    {
        this->bookID=bookID;
        this->title=title;
        this->author=author;
        this->category=category;
        this->price=price;
        available = true;
        borrowedBy = 0;
    }

    void setbookID(int bookID)
    {
        this->bookID=bookID;
    }

    void settitle(string title)
    {
        this->title=title;
    }

    void setAuthor(string author)
    {
        this->author=author;
    }

    void setCategory(string category)
    {
        this->category=category;
    }

    void setPrice(double Price)
    {
        this->price=price;
    }

    void setAvailable(bool a)
    {
        available = a;
    }

    void setBorrowedBy(int id)
    {
        borrowedBy = id;
    }

    int getBookID()
    {
        return bookID;
    }

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    string getCategory()
    {
        return category;
    }

    double getPrice()
    {
        return price;
    }

    bool getAvailable()
    {
        return available;
    }

    int getBorrowedBy()
    {
        return borrowedBy;
    }

    void displayBook()
    {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;

        if (available)
        {
            cout << "Available: Yes" << endl;
        }
        else
        {
            cout << "Available: No" << endl;
            cout << "Borrowed By Member ID: " << borrowedBy << endl;
        }

        cout << "------------------------" << endl;
    }
};

#endif
