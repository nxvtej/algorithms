#include<iostream>
#include<iomanip>
using namespace std;

class rectangle 
{
    private : 
    float length , breadth ;

    public :
    void getData(float length , float breadth);
    void getData1(float &length , float &breadth);
    void getData2(float  *length , float *breadth);
    void putData();
};

void rectangle::getData(float length , float breadth)
{
    rectangle :: length = length ; 
    rectangle :: breadth = breadth ;

}

void rectangle::getData1(float &length , float &breadth)
{
    this->length = length ;
    this->breadth = breadth ;
}

void rectangle::getData2(float *length , float *breadth)
{
    rectangle::length = *length ;
    rectangle::breadth = *breadth ;
    cout<<"values recieved via * are \n"<<*length<<"\n"<<*breadth<<endl;

}

void rectangle ::putData ()
{
    cout<< setprecision(20);
    cout << "area of the rectangle is : "<<length*breadth ;

}

int main()
{
    float length , breadth ;
    rectangle r1;
    cout<<"enter the length and breadth"<<endl;
    cin>>length >> breadth ;

    cout << "1st case values will be passed via call by value method"<<endl;
    r1.getData(length , breadth);

    cout<<"2nd case values will be pased  via call by reference method"<<endl;
    r1.getData1(length , breadth);

    cout<<"3rd case values will be passed via call by address"<<endl;
    r1.getData2(&length , &breadth);

    r1.putData();
    return 0;
}