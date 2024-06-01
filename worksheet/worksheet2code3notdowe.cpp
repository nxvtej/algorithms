#include<string.h>
#include<iostream>
using namespace std;
class student
{
    char name[20];
    public :
    static int roll_number ;
    static int count ;
    student()
    {
        roll_number++;
        count++;
    }
    void getdata(char a[20] )
    {
        strncpy(name , a , 20);
    }
    void putdata()
    {
        cout<<" name is  : "<<name<<endl;
        cout<<" roll number : "<<roll_number<<endl;
    }
};
int student::count = 1100;
int student :: roll_number = 0;
int main(void)
{
    char name[20];
    for(int i =0 ; i<5;i++)
    {
    student s[i]; 
    cout<<"enter the name of student : ";
    cin.getline(name,20);
    s[i].getdata(name);
    s[i].putdata();
    }
    cout<<"total object created is : "<<student::count-1100;
}