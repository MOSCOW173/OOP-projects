#include <iostream>
#include<student.h>
#include<teacher.h>
#include<Course.h>
#include<classroom.h>
#include<staff.h>
#include<school.h>
using namespace std;

int main()
{
    School sh;
    int n;
    do
    {
        cout<<"Press 0 To Exit From Program"<<endl;
        cout<<"Press 1 To Add Student"<<endl;
        cout<<"Press 2 To Add Teacher"<<endl;
        cout<<"Press 3 To Add Staff"<<endl;
        cout<<"Press 4 To Add Course"<<endl;
        cout<<"Press 5 To Add Class Room"<<endl;
        cout<<"Press 6 To Print All Students"<<endl;
        cout<<"Press 7 To Print All Teachers"<<endl;
        cout<<"Press 8 To Print All Staffs"<<endl;
        cout<<"Press 9 To Print All Courses"<<endl;
        cout<<"Press 10 To Print All Class Rooms"<<endl;
        cin>>n;
        switch(n)

        {
        case 0:
            return 0;
        case 1:
        {
            student s;
            s.information();
            sh.addstudent(s);
            break;
        }
        case 2:
        {
            teacher t;
            t.information();
            sh.addteacher(t);
            break;
        }
        case 3:
        {
            staff s;
            s.information();
            sh.addstaff(s);
            break;
        }
        case 4:
        {
            Course c;
            c.information();
            sh.addcourse(c);
            break;
        }
        case 5:
        {
            classroom c;
            c.information();
            sh.addclassroom(c);
            break;
        }
        case 6:

            sh.printstudents();
            break;

        case 7:

            sh.printteachers();
            break;

        case 8:

            sh.printstaffs();
            break;

        case 9:

            sh.printcourses();
            break;

        case 10:

            sh.printclassrooms();
            break;

        }
    }
    while(n!=0);
}
