#include<iostream>
using namespace std;

class base
{
    public :

    void print();
};

void base::print()
{
    cout<<"inside the base class's print() function."<<endl; 
}

class derived : public base
{
    public :

    void print()
    {
        cout<<"inside the derived class's print() function."<<endl;
    }
};

int main()
{

    base *base_ptr;
    derived *derived_ptr;
    base base_object1;
    derived derived_object1;

/*
when the pointer created are assigned the objects of different classes.
*/
    base_ptr = &derived_object1;
    //derived_ptr = &base_object1;
    // can't be done as pointer of base class can't be assigned to base classes
    base_ptr->print();
    derived_ptr->print();

/*
when the pointer created are assigned the objects of same classes.
*/
    base_ptr = &base_object1;
    derived_ptr = &derived_object1;

    base_ptr->print();
    derived_ptr->print();

}