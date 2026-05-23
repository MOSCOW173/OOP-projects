#ifndef TEACHER_H
#define TEACHER_H
#include<person.h>
#include<iostream>
using namespace std;
class teacher:public person
{
private:
    string subject;
    float salary;
public:
    teacher()
    {

    }
    teacher(string subject,float salary)
    {
        this->subject=subject;
        this->salary=salary;
    }
    void setSubject(string subject)
    {
        this->subject=subject;
    }
    void setSalary(float salary)
    {
        this->salary=salary;
    }
    string getSubject()
    {
        return subject;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        cout<<"The Subject is : "<<subject<<endl;
        cout<<"The Salart is : "<<salary<<endl;
    }
    void information()
    {
        cout<<"Please Enter your Subject"<<endl;
        cin>>subject;
        cout<<"Please Enter your Salary"<<endl;
        cin>>salary;
    }
};

#endif // TEACHER_H
