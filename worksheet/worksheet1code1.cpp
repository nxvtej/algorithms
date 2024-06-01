#include<iostream>
using namespace std;

class rectangle
{
    private :
    float length , breadth ;

    public :
    void getData()
    { 
        //  write the code for taking the values from the user ;
        cout<<"enter the length of the rectangle"<<endl;
        cin>>length;

        cout<<"enter the breadth of the rectangle"<<endl;
        cin>>breadth ;
    }
    float area()
    {
        // return the area of the rectangle
        return length*breadth ;
    }
};
int main(void)
{
    rectangle c;
    c.getData();
    printf("%f",c.area());
}