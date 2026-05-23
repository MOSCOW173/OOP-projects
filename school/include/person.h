#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class person
{
protected:
    string name;
    int age;
    string gender;
    string address;
    string phoneNumber;
    string email;
    int id;
public:
    person()
    {

    }
    person(string name,int age,string gender,string address,string phoneNumber,string email,int id)
    {
        this->name=name;
        this->age=age;
        this->gender=gender;
        this->address=address;
        this->phoneNumber=phoneNumber;
        this->email=email;
        this->id=id;
    }
    void setName(string name)

    {
        this->name=name;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    void setGender(string gender)
    {
        this->gender=gender;
    }
    void setaddress(string address)
    {
        this->address=address;
    }
    void setphoneNumber(string phoneNumber)
    {
        this->phoneNumber=phoneNumber;
    }
    void setemail(string email)
    {
        this->email=email;
    }
    void setId(int id)
    {
        this->id=id;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;

    }
    string getGender()
    {
        return gender;
    }
    string getAddress()
    {
        return address;
    }
    string getPhoneNumber()
    {
        return phoneNumber;
    }
    string getemail()
    {
        return email;
    }
    int getId()
    {
        return id;
    }

    void print()
    {
        cout<<"The Name Is : "<<name<<endl;
        cout<<"The age Is : "<<age<<endl;
        cout<<"The gender Is : "<<gender<<endl;
        cout<<"The address Is : "<<address<<endl;
        cout<<"The phoneNumber Is : "<<phoneNumber<<endl;
        cout<<"The email Is : "<<email<<endl;
        cout<<"The id Is : "<<id<<endl;
    }
    void information()
    {
        cout<<"Please enter your name : "<<endl;
        cin>>name;
        cout<<"Please enter your age : "<<endl;
        cin>>age;
        cout<<"Please enter your gender : "<<endl;
        cin>>gender;
        cout<<"Please enter your address : "<<endl;
        cin>>address;
        cout<<"Please enter your phoneNumber : "<<endl;
        cin>>phoneNumber;
        cout<<"Please enter your email : "<<endl;
        cin>>email;
        cout<<"Please enter your id : "<<endl;
        cin>>id;
    }
    int main ()
    {
        using namespace std;

    }
};

#endif // PERSON_H
