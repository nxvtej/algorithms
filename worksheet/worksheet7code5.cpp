#include<bits/stdc++.h>
using namespace std;

class new_delete
{
    public :
    string name ;
    int roll_no ;

    // void get_Data();
    new_delete () 
    {
        // get_Data();
    }

    new_delete (string name, int roll_no)
    {

        new_delete :: name = name ;
        new_delete :: roll_no = roll_no ;
    }


    void *operator new(size_t size){
    {
        void *ptr = malloc(size);
        if(ptr!=NULL)
        {
            cout<<"Allocated memory size is : "<<size<<"\n";

        }
            return ptr ;
        }
    }
    
    void operator delete (void *ptr)
    {
        free(ptr);
        cout<<"Deallocated memory \n";
    }

};
/*
void new_delete :: get_Data ()
{
    cout<<"enter the name : \n";
    cin>>name ;
    cout<<"enter the rol number : \n";
    cin>>roll_no;
}
*/

int main(void)
{
    new_delete *obj ;
    obj = new new_delete ("Navdeep" , 2925);
    delete obj;
    return 0 ;
}