#include<iostream>
using namespace std;

class a
{
    protected : 
    void fun1()
    {
        cout<<"inside the function 1 of base a class"<<endl;
    }

    void fun2()
    {
        cout<<"inside the function 2 of base a class"<<endl;
    }
    public :

    void aa()
    {
        cout<<"here"<<endl;
        a :: fun1();
        a :: fun2();
    }

};
class b
{
    protected : 
    void fun1()
    {
        cout<<"inside the function 1 of base b class"<<endl;
    }

    void fun2()
    {
        cout<<"inside the function 2 of base b class"<<endl;
    }
    public :
    void bb()
    {
        cout<<"here"<<endl;
        b :: fun1();
        b :: fun2();
    }

};
class c : protected a , protected b 
{
    public : 
    void cc ()
    {
        a :: aa();
        b :: bb ();
    }
};
int main(void)
{
    c object1;
    object1.cc();
    // object1
}
