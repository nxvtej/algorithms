#include<iostream>
using namespace std;

class AddAmount
{
    private :
    int amount;

    public :
    AddAmount()
    {
        amount = 50;
    }

    AddAmount(int added)
    {
        amount = 50;
        amount += added; 
    }
    void display();

};

void AddAmount::display()
{
    cout<<"the final amount is : "<<amount<<endl;
}

int main(void) 
{
    int add = 0;
    cin>>add;
    
    cout<<"when nothing is addded : "<<endl;
    AddAmount amount; // when nothing is added ;
    amount.display();

    cout<<"after adding : "<<endl;

    AddAmount amount1(add);
    amount.display();
}