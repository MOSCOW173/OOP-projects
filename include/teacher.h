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
    teacher(string name,int age,string gender,string address,string phoneNumber,string email,int id
            ,string subject,float salary)
    {
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->address=address;
        this->phoneNumber=phoneNumber;
        this->email=email;
        this->id=id;
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
        person::print();
        cout<<"The Subject is : "<<subject<<endl;
        cout<<"The Salart is : "<<salary<<endl;
    }
    void information()
    {
        person::information();
        cout<<"Please Enter your Subject"<<endl;
        cin>>subject;
        cout<<"Please Enter your Salary"<<endl;
        cin>>salary;
    }
};

#endif // TEACHER_H
