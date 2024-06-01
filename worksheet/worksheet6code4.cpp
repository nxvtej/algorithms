#include <iostream>
using namespace std;

class base 
{
    public :
    virtual void print() = 0; 

};

class derived : public base
{
    public :
    void print()
    {
        cout<<"your in the derived class\nthanks bye "<<endl;
    }
};

int main(void)
{
    base *ptr1;
    derived *ptr2;
    ptr1 = new derived();
    ptr2 = new derived();
    ptr1 -> print();
    ptr2 -> print();
}