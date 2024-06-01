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
    cout<<"enter the size of array"<<endl;

    cin>>n;
    arr = new int[n];

    cout<<"enter the enteries of arrau : "<<endl;
    for(int i=0; i<n; i++)
    cin>>arr[i];

     cout<<"output :";
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
    a.displayData();

    return 0 ;
}