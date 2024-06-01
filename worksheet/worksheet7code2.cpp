/*// pre increment operator via member function
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

    void operator ++ ()
    {
        ++pnumber ; 
        ++dnumber ;
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

    cout<<"values after the ++ operator overloading "<<endl;
    ++navdeep;
    navdeep.print_data();

    cout<<"code ends\n";
}
*/
// post increment operator via member function
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

    void operator ++ (int)
    {
        pnumber++ ; 
        dnumber++ ;
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

    cout<<"values after the ++ operator overloading "<<endl;
    navdeep++;
    navdeep.print_data();

    cout<<"code ends\n";
}
