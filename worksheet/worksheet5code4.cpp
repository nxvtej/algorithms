/*
diamond ambiguity comes  when the derived class is multiple inheritance with the
two derived classes B and C whose base class is a that 
time we get copies of two member fuction / variables 
and to over come this we can make the use of virtual keyword .

or we can use  the scope resolution at specific time
to emet requirement

*/
#include<iostream>
using namespace std;

class base1
{
    public :
    int adc ;

    int abc()
    {
        adc = 70 ;
        // cout<<"inside the base 1 operator \n"<<adc<<endl;
        return adc  ;
    }

};

class derived1  : public base1
{
    public :
    
    int abc()
    {   
        adc = 99 ;
        // cout<<"inside the derived 1 operator \n"<<adc<<endl;
        return adc ;
    }

};

class derived2 : public base1
{
    public :

    int abc()
    {
        adc =1 ;
        // cout<<"inside the derived 2 operator \n"<<adc<<endl;
        return adc ; 
    }

};

class derived3 : public derived1, public derived2
{
    public :

    void operation ()
    {
        cout<<"the addition is "<<derived1 :: abc() + derived2 :: abc ()<<endl; 
    }


};

int main(void)
{
    // base1 *ptr;
    // derived3 object;
    // ptr = &object;
    // ptr.base1 :: abc();

    // object.base1::abc();

    derived3 obj ;
    cout<<"first number is : " <<obj.derived1:: abc();
    cout<<endl;

    cout<<"second number is : " <<obj.derived2:: abc()<<endl;
    obj.operation();

}

/*
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

#include<iostream>
using namespace std;
class base1
{
    int x =70;
    public:
    int show()
    {
        return x;
    }
};
class base2
{
    int y=30;
    public:
    int show()
    {
        return y;
    }
};
class deriv: public base1,public base2
{
    public:
    void sum ()
    {
        cout<<"the total is "<<(base1::show()+base2::show())<<endl;
    }
};
int main()
{
    deriv x;
    x.sum();
    cout<<x.base1::show()<<endl;
    cout<<x.base2::show()<<endl;
}
*/