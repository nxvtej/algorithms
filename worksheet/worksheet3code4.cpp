#include<bits/stdc++.h>
using namespace std;
class b;
class a
{
    private :

    int real , imaginary ;
    friend int complex_real_sum(a,b);
    friend int complex_imag_sum(a,b);

    public :
    void getdata(int &A , int &B);
};
void a :: getdata(int &A , int &B)
{
    real = A ;
    imaginary = B ;
}
class b 
{
    private :

    int real , imaginary ;
    friend int complex_real_sum(a,b);
    friend int complex_imag_sum(a,b);

    public :
    void  getdata(int &A , int &B);

};
void b :: getdata(int &A , int &B)
{
    real = A ;
    imaginary =B ;
}
int complex_real_sum(a obj1, b obj2)
{
    int real_sum = obj1.real + obj2.real;
    return real_sum;
}
int complex_imag_sum(a obj1 , b obj2)
{
    int imaginary_sum = obj1.imaginary + obj2.imaginary ;
    return imaginary_sum;
}
int main(void)
{
    int x , y;
    a obj1;
    b obj2;

    cout<<"enter the values for first complex number : "<<endl;
    cout<<"enter real and imaginary values : "<<endl;
    cin>>x>>y;
    obj1.getdata(x,y);

    cout<<"enter the values for the second complex number : "<<endl;
    cout<<"enter the real and imaginary values :"<<endl;
    cin>>x>>y;
    obj2.getdata(x,y);

    int sum1 = complex_real_sum(obj1,obj2);
    int sum2 = complex_imag_sum(obj1,obj2);
    cout<<"the sum of the  two complex numbers are : "<<sum1<<"+"<<sum2<<"i "<<endl;
}
/*
class complex 
{
    public :
    int real , imaginary ;

    complex (int real ,int imaginary) 
    {
        complex ::real=real;
        complex :: imaginary=imaginary;
    }
    
    complex addcomp(complex c1, complex c2)
    {
        complex temp ; 

        temp.real = c1.real +c2.real ;
        temp.imaginary = c1.imaginary + c2.imaginary ;
        return temp ; 
    }

};

int main()
{
    complex c1(2,3);
    cout<<"first complex number is : "<<c1.real << " +  i"<<c1.imaginary<<endl;

    complex c2(9,5);
    cout<<"second complex number is : "<<c2.real<<" + i"<<c2.imaginary<<endl;

    complex c3;
    c3 = c3.addcomp(c1,c2);

    cout<<"sum of the complex numers is : "<<c3.real << " + i"<<c3.imaginary;

}*/