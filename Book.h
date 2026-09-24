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
        : bookID(0), title(""), author(""), category(""),
          price(0), available(true), borrowedBy(0)
    {
    }

    Book(int bookID, string title, string author, string category, double price)
        : bookID(bookID),
          title(title),
          author(author),
          category(category),
          price(price),
          available(true),
          borrowedBy(0)
    {
    }

    void setbookID(int bookID)
    {
        this->bookID = bookID;
    }

    void setTitle(string title)
    {
        this->title = title;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }

    void setCategory(string category)
    {
        this->category = category;
    }

    void setPrice(double price)
    {
        if (price > 0)
        {
            this->price = price;
        }
        else
        {
            cout << "Price must be greater than 0!" << endl;
        }
    }

    void setAvailable(bool available)
    {
        this->available = available;
    }

    void setBorrowedBy(int id)
    {
        borrowedBy = id;
    }

    int getBookID() const
    {
        return bookID;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getCategory() const
    {
        return category;
    }

    double getPrice() const
    {
        return price;
    }

    bool getAvailable() const
    {
        return available;
    }

    int getBorrowedBy() const
    {
        return borrowedBy;
    }
};

#endif
