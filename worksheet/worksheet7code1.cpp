//  overloading unary operator (-) via member function 
/*
#include<iostream>
using namespace std;

class operator_new
{
    private :
    int pnumber , dnumber ;

    public :
    operator_new()
    {
        pnumber = 0 ;
        dnumber = 0 ;
    }
    operator_new(int pnumber , int dnumber)
    {
        this->pnumber = pnumber;
        this->dnumber = dnumber;
    }

    void print_data();

    void operator - ()
    {
        pnumber = -pnumber ; 
        dnumber = -dnumber ;
    }
};

void operator_new :: print_data()
{
    // cout<<"here is the result "<<endl;
    cout<<"pnumber = "<<pnumber<<endl;
    cout<<"dnumber = "<<dnumber<<endl;
    // cout<<"code ends here ! ";
} 

int main(void)
{
    cout<<"initial values "<<endl;
    operator_new navdeep(22 , 32) ; 
    navdeep.print_data();

    cout<<"values after the - unary operator overloading "<<endl;
    -navdeep;
    navdeep.print_data();

    cout<<"code ends\n";
}
*/
// overloading unary operator (-) via friend function
#include<iostream>
using namespace std;

class operator_new ;
class operator_old
{
    private :
    int pnumber , dnumber ;

    public :
    operator_old()
    {
        pnumber = 0 ;
        dnumber = 0 ;
    }

    operator_old (int pnumber , int dnumber)
    {
        this->pnumber = pnumber;
        this->dnumber = dnumber;
    }

    void print_data();

    void friend operator - (operator_new &object1 , operator_old &object2) ;
};
class operator_new
{
    private :
    int pnumber , dnumber ;

    public :
    operator_new()
    {
        pnumber = 0 ;
        dnumber = 0 ;
    }
    operator_new(int pnumber , int dnumber)
    {
        this->pnumber = pnumber;
        this->dnumber = dnumber;
    }

    void print_data();

    void friend operator - (operator_new &object1 , operator_old &object2) ;
};

void operator_new :: print_data()
{
    cout<<"here is the values of operator_new class "<<endl;
    cout<<"pnumber = "<<pnumber<<endl;
    cout<<"dnumber = "<<dnumber<<endl;
    // cout<<"code ends here ! ";
} 


void operator_old :: print_data()
{
    cout<<"here is the values of operator_old class "<<endl;
    cout<<"pnumber = "<<pnumber<<endl;
    cout<<"dnumber = "<<dnumber<<endl;
    // cout<<"code ends here ! ";
} 

void operator - (operator_new &object1 , operator_old &object2)
{
    object1.dnumber = -object1.dnumber;
    object1.pnumber = -object1.pnumber;
    object2.dnumber = -object2.dnumber;
    object2.pnumber = -object2.pnumber;

}


int main(void)
{
    cout<<"initial values "<<endl;
    operator_new navdeep(-34 , 23) ; 
    navdeep.print_data();
    operator_old navtej(-21 , 32) ; 
    navtej.print_data();

    cout<<"values after the - unary operator overloading "<<endl;
    operator - (navdeep , navtej);
    navdeep.print_data();
    navtej.print_data();

    cout<<"code ends\n";
}

/*
#include<iostream>
using namespace std;
class UnaryFriend
{
     int a=10;
     int b=20;
     int c=30;
     public:
         void getvalues()
         {
              cout<<"Values of A, B & C\n";
              cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<endl;
         }
         void show()
         {
              cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<endl;
         }
         void friend operator-(UnaryFriend &x);      //Pass by reference
};
void operator-(UnaryFriend &x)
{
     x.a = -x.a;     //Object name must be used as it is a friend function
     x.b = -x.b;
     x.c = -x.c;
}
int main()
{
     UnaryFriend x1;
     x1.getvalues();
     cout<<"Before Overloading\n";
     x1.show();
     cout<<"After Overloading \n";
     -x1;
      x1.show();
      return 0;
}*/