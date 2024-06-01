/*/*
when ever we define the objectv of any class then by default the constructor is called and
if the body in which the object is been defined ends then at that point
the destructpr will also be executedd automatically ,
for example 


#include<iostream>
using namespace std;

class Student
{
    
    static int count;

    public :
    Student ()
    { 
        count++;
        cout<<"constructor called"<<endl;
    }
    ~Student ()
    {
        cout<<"destructor called"<<endl;
    }

    
};

int Student :: count =0;

void tempfun()
{
    Student s;
}
int main()
{
    tempfun();
    Student s1;
    cout<<"last line of the code"<<endl;
    return 0;

}
*/
/*now if we ise static keyword with the objected called in the
fucntion then the destructor is called at last ;
*/

#include<iostream>
using namespace std;

class Student
{
    
    static int count;

    public :
    Student ()
    { 
        count++;
        cout<<"constructor called"<<endl;
    }
    ~Student ()
    {
        cout<<"destructor called"<<endl;
    }

    
};

int Student :: count =0;

void tempfun()
{
    static Student s;
}
int main()
{
    tempfun();
    Student s1;
    cout<<"last line of the code"<<endl;
    return 0;

}