#ifndef SCHOOL_H
#define SCHOOL_H
#include<student.h>
#include<teacher.h>
#include<staff.h>
#include<Course.h>
#include<classroom.h>
using namespace std;
class School
{
private:
    string schoolName;
    string address;
    string principalName;
    student students[1000];
    teacher teachers[50];
    staff staffs[50];
    Course courses[6];
    classroom classrooms[50];
    int studentcounter=0;
    int teachercounter=0;
    int staffcounter=0;
    int coursecounter=0;
    int classroomcounter=0;
public:
    void addstudent(student s)
    {
        students[studentcounter]=s;
        studentcounter++;
    }
    void addteacher(teacher t)
    {
        teachers[teachercounter]=t;
        teachercounter++;
    }
    void addstaff(staff s)
    {
        staffs[staffcounter]=s;
        staffcounter++;
    }
    void addcourse(Course c)
    {
        courses[coursecounter]=c;
        coursecounter++;
    }
    void addclassroom(classroom c)
    {
        classrooms[classroomcounter]=c;
        classroomcounter++;
    }
    void printstudents()
    {
        for(int i=0; i<studentcounter; i++)
        {
            students[i].print();
            cout<<endl;
        }
    }
    void printteachers()
    {
        for(int i=0; i<teachercounter; i++)
        {
            teachers[i].print();
            cout<<endl;
        }
    }
    void printstaffs()
    {
        for(int i=0; i<staffcounter; i++)
        {
            staffs[i].print();
            cout<<endl;
        }
    }
    void printcourses()
    {
        for(int i=0; i<coursecounter; i++)
        {
            courses[i].print();
            cout<<endl;
        }
    }
    void printclassrooms()
    {
        for(int i=0; i<classroomcounter; i++)
        {
            classrooms[i].print();
            cout<<endl;
        }
    }
};

#endif // SCHOOL_H
