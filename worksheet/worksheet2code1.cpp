#include<string.h>
#include<iostream>
using namespace std;
class student
{
    // static int count ;
    int roll_number ;
    char name[20];

    public :
    static int count ;
    student()
    {
        roll_number = count - 1100 + 1;
        count++;
    }
    void getdata(char a[20] )
    {
        strncpy(name , a , 20);
        
    }
    void putdata()
    {
        cout<<" roll number : "<<roll_number<<endl;
        cout<<" name is  : "<<name<<endl;
    }
};
int student::count = 1100;
int main(void)
{
    char name[20];

    student s1; 
    cout<<"enter the name of student : ";
    cin.getline(name,20);
    s1.getdata(name);
    s1.putdata();
    cout<<"total object created is : "<<student::count-1100;
}
