#include<iostream>
#include<string.h>
#include<sstream>

using namespace std;
class student
{
    private :

    char name[20];
    int roll_no , marks[3];
    int total(void);

    public :

    void set_data(char A[20] , int r , int b[3]);
    void display_data()
    {
        cout<<"NAME OF THE STUDENT IS : "<<name<<endl;
        cout<<"ROLL NUMBER OF "<<name<<" IS : "<<roll_no<<endl;
        cout<<"TOTAL MARKS OF ROLL NUMBER "<<roll_no<<" IS : ";
        total();
        cout<<endl;
    }
};
int student :: total()
{
    int t=0;
    for(int i=0; i<3;i++)
    t+=marks[i];
    cout<<t;
}
void student :: set_data(char A[20] , int r , int b[3])
{
    // stringstream ss;
    // ss << A[20] ;
    // ss >> name ;
    strncpy(name,A,20);

    roll_no = r;

    for(int i = 0; i <3;i++)
    {

        marks[i] =b[i];
    }



}
int main()
{
    char name[20];
    int roll_no,marks[3];

    student s1;

    cout<<"enter the name : "<<endl;
    cin.getline(name,20);
    cout<<"set the roll : "<<endl;
    cin>>roll_no;
    cout<<"set the marks of 3 subjects : "<<endl;

    for(int i =0 ;i<3;i++)
    {
        cin>>marks[i];
    }

    s1.set_data(name , roll_no , marks);

    s1.display_data();
    return 0;
}