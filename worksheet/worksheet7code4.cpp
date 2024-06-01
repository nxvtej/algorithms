
#include<iostream>
using namespace std;

class both_codes 
{
    public :
    string navdeep ; 

    friend istream& operator>>(istream &inp, both_codes &object_here)
    {
        cout<<"Enter you name : \n"; 
        inp>>object_here.navdeep;
        return inp;
    }

    friend ostream& operator<<(ostream &out , both_codes &object_here)
    {
        out<<"Name entered : "<<object_here.navdeep<<"\n";
        return out;
    }
};

int main(void)
{
    both_codes roll_no1 , roll_no2 ;
    cin>>roll_no1>>roll_no2;
    cout<<roll_no1<<roll_no2;
    return 0;
}