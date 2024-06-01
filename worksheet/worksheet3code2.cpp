#include<iostream>
using namespace std;

class rectangle
{
    private :
    float length;
    float breadth;

    public :
    void getData(float length , float breadth);
    float area() ;
};
void rectangle::getData(float length , float breadth)
{
    this->length = length;
    this->breadth = breadth;
//     rectangle :: length = length ; 
//     rectangle :: breadth = breadth ;
}

float rectangle::area()
{
    return length*breadth ;
}

int main(void)
{
    float length , breadth ; 
    cin>>length>>breadth ; 

    rectangle r ; 
    r.getData(length, breadth);
    cout<<"area of the rectangel is : "<<r.area()<<endl;

}