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
    void getdata()
    {
        cin>>name;
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
    int n;
    cout<<"enter the value of n : "<<endl;
    cin>>n;
    student *s;
    s= new student[n];
    for(int i =0 ; i < n ; i++)
    {
    // cout<<"enter the name of student : ";   // cin.getline(name,20);
    s[i].getdata();
    s[i].putdata();
    }
    cout<<"total object created is : "<<student::count-1100;
}