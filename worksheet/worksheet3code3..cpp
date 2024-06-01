#include<iostream>
using namespace std;

class Dummy
{
int num;
public:

void get_Data(void);
 // to take the input of num from the user
void set_Data(Dummy d1) ;
/* to set the value of the data member of one object to an
another object; this is call by value.*/
void set_Data(int dummy, Dummy &d1) ;
/*to set the value of the data member of one
object to an another object; this is call by reference as Dummy &d1 is used. Here
int dummy is a dummy parameter as otherwise the compiler will give error because
it cant differentiate between call by value and call by reference.*/
void set_Data(Dummy *d1) ; 
/*to set the value of the data member of one object to an
another object; this is call by addres as Dummy *d1 is used.*/

void show_Data(); // to display the value of num as set
};

void Dummy :: set_Data(Dummy d1)
{
    cout<<"enter the number "<<endl;
    cin>>num;
}

void Dummy :: set_Data(int dummy , Dummy &d1)
{
    this-> num = d1.num;
}

void Dummy :: set_Data(Dummy *d1)
{
    this-> num =d1->num;
}
void Dummy :: show_Data()
{
    cout<<this->num<<endl;
}

int main()
{

Dummy d1,d2,d3,d4;
d1.get_Data();
d2.set_Data(d1);
d3.set_Data(0,d1);
d4.set_Data(&d1);

cout<<"the value of object d1 is ";
d1.show_Data();
cout<<"the value of object 2 is";
d2.show_Data();
cout<<"the value of object d3 is";
d3.show_Data();
cout<<"the value of object d4 is";
d4.show_Data();
}
//get the value of num for d1 using get_Data()
//set the value of num for d2 equal to value of num for d1 using call by value.
//set the value of num for d3 equal to value of num for d1 using call by reference.
//set the value of num for d4 equal to value of num for d1 using call by address.
//print the value of num for d1,d2,d3 and d4.