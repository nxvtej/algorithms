#include<iostream>
using namespace std;
class abc
{
  
   public :
   abc* get(void)
   {
      return this ;
      // cout<<"the addres of the object via function is  : "<<a;
   }
};

int main()
{
   abc a;
   cout<<"the address of the object in main is : "<<&a<<endl;
   abc *c;
   c=a.get();
   cout<<"the address of the object comming from class function : "<<c<<endl;
   return 0 ;
}