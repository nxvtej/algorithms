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

        a :: fun1();
        a :: fun2();
    }

};
class b : protected a
{
    protected : 
    void fun3()
    {
        cout<<"inside the function 3 of base b class"<<endl;
    }
    public :
    void bb()
    {
        
        b :: fun3();
        a :: aa();
    }

};
class c : protected a 
{
    protected : 
    void fun3()
    {
        cout<<"inside the function 3 of base c class"<<endl;
    }

    public :
    void cc()
    {

        c :: fun3();
    }
};

class d : public b , public c 
{

    public :
    void fun5()
    {
        cout<<"inside the function 5 of base d class"<<endl;
        c :: cc();
        b :: bb();
    }

};
int main(void)
{
    d object1;
    object1.fun5();
    
    // object1
}
