#ifndef Member_H
#define Member_H
#include <iostream>
#include <string>

using namespace std;

class Member
{
private:
    int memberID;
    string name;
    string phone;
    string email;

public:

    Member()
    {
        memberID = 0;
        name = "";
        phone = "";
        email = "";
    }

    Member(int memberID, string name, string phone, string email)
    {
        this->memberID=memberID;
         this->name = name;
         this->phone = phone;
        this-> email = email;
    }

    void setMemberID(int id)
    {
        memberID = id;
    }

    void setName(string n)
    {
        name = n;
    }

    void setPhone(string p)
    {
        phone = p;
    }

    void setEmail(string e)
    {
        email = e;
    }

    int getMemberID()
    {
        return memberID;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }

    string getEmail()
    {
        return email;
    }

    void displayMember()
    {
        cout << "Member ID: " << memberID << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "------------------------" << endl;
    }
};

#endif
