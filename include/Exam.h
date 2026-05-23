#ifndef EXAM_H_
#define EXAM_H_


class Exam.h
{
private:
    string examName;
    string courseName;
    string examDate;
public:
    exam()
    {

    }
    exam(string examName,string courseName,string examDate)
    {
        this->examName=examName;
        this->courseName=courseName;
        this->examDate=examDate;
    }
    void setexamName(string eaxmName)
    {
        this->examName=examName;
    }
    void setcourseName(string courseName)
    {
        this->courseName=courseName;
    }
    void setexamDate(string examDate)
    {
        this->examDate=examDate;
    }
    string getexamName()
    {
        return examName;
    }
    string getcourseName()
    {
        return courseName;
    }
    string getexamDate()
    {
        return examDate;
    }
    void print()
    {
        cout<<"The ExamName Is : " <<examName<<endl;
        cout<<"The CourseName Is : " <<courseName<<endl;
        cout<<"The ExamDate Is : " <<examDate<<endl;

    }
    void information()
    {
        cout<<"Please Enter your ExamName : " <<endl;
        cin>>examName;
        cout<<"Please Enter your CourseName : " <<endl;
        cin>>courseName;
        cout<<"Please Enter your ExamDate : " <<endl;
        cin>>examDate;
    }
};

#endif // EXAM_H_
