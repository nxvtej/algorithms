#include<iostream>
using namespace std;
class B;
class A{
int x;
public:
void getdata(){
cout<<"Enter val\n";
cin>>x;
}
friend int operator / (A&,B&);
friend int operator % (A&,B&);
};
class B{
int y;
public:
void getdata(){
cout<<"Enter val\n";
cin>>y;
}
friend int operator / (A&,B&);
friend int operator % (A&,B&);
};
int operator/(A &a,B &b){
    int val;
val=a.x/b.y;
return val;
}
int operator%(A &a,B &b){
int val;
val=a.x%b.y;
return val;
}
int main(){
int div,mod;
A a1;
B b1;
a1.getdata();
b1.getdata();
div=a1/b1;
mod=a1%b1;
cout<<"Value after division "<<div<<endl;
cout<<"Value after modulus "<<mod;
return 0;
}