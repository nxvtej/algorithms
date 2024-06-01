#include <iostream>
using namespace std;

class bache 
{
    private :
    int *dynamic_array ;
    int dynamic_array_size ;

    public :

    class Error{};
    bache(){}

    bache(int dynamic_array_size)
    {
        this->dynamic_array_size = dynamic_array_size;
        dynamic_array = new int[dynamic_array_size];
    }

    void get_value()
    {
        cout<<"enter the values of array\n";
        for(int i=0; i<dynamic_array_size;i++)
        {
            cin>>dynamic_array[i];
        }
    }

    void dispose()
    {
        cout<<"entered the values of array :\n";
        for(int i=0; i<dynamic_array_size;i++)
        {
            cout<<i<<". "<<dynamic_array[i]<<"\n";
        }
    }

    int & operator[](int index)
    {
        if(index < 0 || index >= dynamic_array_size)
        throw Error();

        else
        return dynamic_array[index];
    }

};

int main(void)
{
    cout<<"enter the total number of dynamic arrays : "<<endl;
    int size{};
    cin>>size;

    bache baap(size);

    baap.get_value();
    baap.dispose();

    int flag = 0;

    start :
    try
    {

        cout<<"enter the index which you want to change along with the value : \n";
        int user_index{} , user_value{} ;
        cin>>user_index >> user_value;

        baap[user_index] = user_value;

        cout<<"now : \n";
        baap.dispose();

        cout<<"want to play again \n if yes then enter 1 :";
        cin>>flag;
        if(flag == 1)
        goto start ;

    }
    catch(bache :: Error)
    {
        std::cerr << "BHAISHAB ye kuch edhar udhar nhi ho gya" << '\n';
        cout<<"dobara try kroge \n if yes then enter 1 :";
        cin>>flag;
        goto start ;

    }
}