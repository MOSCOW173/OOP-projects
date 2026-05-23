#ifndef STAFF_H
#define STAFF_H
#include<person.h>
#include<iostream>
using namespace std;

class staff:public person
{
private:
    string role;
    float salary;
public:
    staff()
    {

    }
    staff(string role,float salary)
    {
        this->role=role;
        this->salary=salary;
    }
    void setRole(string role)
    {
        this->role=role;
    }
    void setSalary(float salary)
    {
        this->salary=salary;
    }
    string getRole()
    {
        return role;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        cout<<"The Role Is : "<<role<<endl;
        cout<<"The Salary Is : "<<salary<<endl;
    }
    void information()
    {
        cout<<"Please Enter Your Role : "<<endl;
        cin>>role;
        cout<<"Please Enter Your Salary : "<<endl;
        cin>>salary;
    }
};

#endif // STAFF_H
