#ifndef COURSE_
#define COURSE_
#include<iostream>
using namespace std;

class Course:public person
{
private:
    string courseCode;
    string courseName;
    string teacherName;
public:
    course()
    {

    }
    course(string courseCode,string courseName,string teacherName)
    {
        this->courseCode=courseCode;
        this->courseName=courseName;
        this->teacherName=teacherName;
    }
    void setcourseCode(string courseCode)
    {
        this->courseCode=courseCode;

    }
    void setcourseName(string courseName)
    {
        this->courseName=courseName;

    }
    void setteacherName(string teacherName)
    {
        this->teacherName=teacherName;

    }
    string getcourseCode()
    {
        return courseCode;
    }
    string getcourseName()
    {
        return courseName;
    }
    string getteacherName()
    {
        return teacherName;
    }
    void print()
    {
        cout<<"The CourseCode IS : "<<courseCode<<endl;
        cout<<"The CourseName IS : "<<courseName<<endl;
        cout<<"The teacherName IS : "<<teacherName<<endl;
    }
    void information()
    {
        cout<<"Please Enter The CourseCode : "<<endl;
        cin>>courseCode;
        cout<<"Please Enter The courseName : "<<endl;
        cin>>courseName;
        cout<<"Please Enter The TeacherName : "<<endl;
        cin>>teacherName;
    }
};

#endif // COURSE_H_
