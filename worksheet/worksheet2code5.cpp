#include<iostream>
using namespace std;
class Array
{
    private :
    int *arr;
    int size ;
   
    public :
     int sum = 0, average= 0 ;
    int n;
    void getData(int n);
    void displayData();
};
void Array :: getData(int n)
{
    cout<<"entered in get data"<<endl;
    cin>>n;
    arr = new int[n];
    cout<<"entered in array";
    for(int i=0; i<n; i++)
    cin>>arr[i];
     cout<<"sum of the enter array :";
    for(int i =0; i<n ;i++)
    {  
        sum += arr[i];
    }
     average = sum / n;
}
void Array :: displayData()
{  
    cout<<"sum is : "<<sum<<endl;
    cout<<"average is : "<<average<<endl;
}

int main()
{
    int n;
    Array a;
    a.getData(n);
    cout<<"back in main"<<endl;

    a.displayData();

    cout<<"after the display function"<<endl;


    return 0 ;
}