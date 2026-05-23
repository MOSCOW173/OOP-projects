#ifndef STUDENT_H
#define STUDENT_H
#include<person.h>
#include<iostream>
using namespace std;
class student:public person
{
private:
    string gradeLevel;
    float gpa;
public:
    student()
    {

    }
    student(string name,int age,string gender,string address,string phoneNumber,string email,int id,
            string gradeLevel,float gpa)
    {
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->address=address;
        this->phoneNumber=phoneNumber;
        this->email=email;
        this->id=id;
        this->gradeLevel=gradeLevel;
        this->gpa=gpa;
    }
    void setGradeLevel(string gradeLevel)
    {
        this->gradeLevel=gradeLevel;
    }
    void setGpa(float gpa)
    {
        this->gpa=gpa;
    }
    string getGradeLevel()
    {
        return gradeLevel;
    }
    float getGPA()
    {
        return gpa;
    }
    void print()
    {
        person::print();

        cout<<"The GradeLevel Is : "<<gradeLevel<<endl;
        cout<<"The Gpa Is : "<<gpa<<endl;
    }
    void information()
    {
        person::information();
        cout<<"Please Enter your Grade Level : "<<endl;
        cin>>gradeLevel;
        cout<<"Please Enter your Gpa : "<<endl;
        cin>>gpa;

    }

};

#endif // STUDENT_H
