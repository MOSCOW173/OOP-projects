#ifndef MEMBER_H
#define MEMBER_H

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

    Member(int memberID, const string& name,
           const string& phone,
           const string& email)
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

    void setName(const string& name)
    {
        this->name = name;
    }

    void setPhone(const string& phone)
    {
        this->phone = phone;
    }

    void setEmail(const string& email)
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