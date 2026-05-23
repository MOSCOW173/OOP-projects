#ifndef CLASSROOM_
#define CLASSROOM_
#include<iostream>

class classroom
{
    private:
    int roomNumber;
    int capacity
public:
    classroom()
    {

    }
    classroom(int roomNumber,int capacity)
    {
        this->roomNumber=roomNumber;
        this->capacity=capacity;
    }
    void setroomNumber(int roomNumber)
    {
        this->roomNumber=roomNumber;

    }
    void setcapacity(int capacity)
    {
        this->capacity=capacity;

    }
    int getroomNumber()
    {
        return roomNumber;
    }
    int getcapacity()
    {
        return capacity;
    }
    void print()
    {
        cout<<"The roomNumber IS : "<<roomNumber<<endl;
        cout<<"The capacity IS : "<<capacity<<endl;
    }
    void information()
    {
        cout<<"Please Enter The roomNumber : "<<endl;
        cin>>roomNumber;
        cout<<"Please Enter The capacity : "<<endl;
        cin>>capacity;
    }
};

#endif // CLASSROOM_
