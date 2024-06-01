#include<iostream>
using namespace std;

class base
{
    public :

    virtual void print();
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

int main(void)
{
    base base_object1;
    derived derived_object1;

/*
when the pointer created are assigned the objects of same classes.
*/
    base *base_ptr = &base_object1;
    base_ptr->print();
    
    base *base_ptr2 = &derived_object1;
    base_ptr ->print();
}