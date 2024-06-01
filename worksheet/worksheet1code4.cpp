#include<iostream>
using namespace std;

class rectangle
{
    private :
    float length , breadth ;

    public :
    void getData(float,float);
    float area();
};
    void rectangle :: getData(float a , float b)
    { 
        //  write the code for taking the values from the user ;
        length=a;
        breadth =b;
    }
    float rectangle :: area()
    {
        // return the area of the rectangle
        return length*breadth ;
    }
int main(void)
{
    float length = 0 , breadth=0 ;
    rectangle c;
    
        //  write the code for taking the values from the user ;
        cout<<"enter the length of the rectangle"<<endl;
        cin>>length;

        cout<<"enter the breadth of the rectangle"<<endl;
        cin>>breadth ;
    c.getData(length , breadth);
    printf("%f",c.area());
}