#ifndef MEMBER_H
#define MEMBER_H

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
        : memberID(0), name(""), phone(""), email("")
    {
    }

    Member(int memberID, string name, string phone, string email)
        : memberID(memberID),
          name(name),
          phone(phone),
          email(email)
    {
    }

    void setMemberID(int id)
    {
        memberID = id;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setPhone(string phone)
    {
        this->phone = phone;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    int getMemberID() const
    {
        return memberID;
    }

    string getName() const
    {
        return name;
    }

    string getPhone() const
    {
        return phone;
    }

    string getEmail() const
    {
        return email;
    }
};

#endif
