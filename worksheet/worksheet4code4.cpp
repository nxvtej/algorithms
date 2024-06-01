#include<iostream>
using namespace std;

class cons_des
{
    int *arr;
    int size;

    public :
    cons_des(){}
    cons_des(int size)
    {
        this->size=size;
        //(*this).size=size;
        arr=new int[size];
        for(int i=0;i<size;i++)
        // scanf("%d",arr+i);
        cin>>*(arr+i);
    }

    void showData();
    ~cons_des()
    {delete arr;}
};

void cons_des :: showData()
{
    for ( int i = 0 ; i < size ; i++)
    {
        cout<< (arr[i])<<endl;
        /* code */
    }
}

int main()
{
    int size;
    cout<<"enter the size of array : ";
    cin>>size;
    cons_des s1(size) ;
    //showData(size);
    return 0;
}