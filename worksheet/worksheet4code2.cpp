#include<iostream>
using namespace std;

class rectangle 
{
    float length , breadth ;
    public :
    rectangle()
    {
        length = 0.0;
        breadth = 0.0;
    }

    rectangle(float length , float breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

    rectangle(float xx )
    {
        length = xx;
        breadth = xx;
    }

    void area();
};

void rectangle :: area()
{
    cout<<"the area of the rectangle is : "<<length*breadth<<endl;
}

int main(void)
{
    float length , breadth ;
    cin>>length>>breadth;

    rectangle rect ;
    rect.area();
    rectangle rect1(88.23);
    rect1.area();
    rectangle rect2 (length , breadth);
    rect2.area();
    

}
