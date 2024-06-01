/*#include<iostream>
using namespace std;

class disk_data
{
    private : 
    int m_Num , n_Num ;

    public :
    disk_data(){}
    disk_data(int m_Num , int n_Num)
    {
        this->m_Num = m_Num ;
        this->n_Num = n_Num ;
    }

    void print_data()
    {
        cout<<"here are the values : \n";
        cout<<"m_Num is : "<<m_Num<<endl;
        cout<<"n_Num is : "<<n_Num<<endl;
        cout<<"okay! \n";
    }

    disk_data operator % (disk_data &object1 )
    {
        disk_data result;
        result.m_Num = this->m_Num % object1.m_Num;
        result.n_Num = this->n_Num % object1.n_Num;

        // result.m_Num = disk_data.m_Num % object1.m_Num;
        return result;
    }
    disk_data operator / (disk_data &object2)
    {
        disk_data result2 ;
        result2.m_Num = 32 / object2.m_Num;
        result2.n_Num = this->n_Num / object2.n_Num;
        return result2;
    }

};

int main(void)
{
    disk_data object(2,5);
    disk_data object2(12,62);

    cout<<"values before the & operator overloading\n";
    object.print_data();
    object2.print_data();

    cout<<"values after the / operator overlaoding \n";
    disk_data object3 = object%object2;
    object3.print_data();

    cout<<"values after the % operator overloading\n";
    disk_data object4 = object % object2;
    object4.print_data();

    cout<<"code ends\n";
}*/

#include <iostream>
using namespace std;

class rom ;
class ram 
{

    public : 
    float a_Num , b_Num; 

    public :
    ram()
    {
        a_Num = 0 ;
        b_Num = 0;
    }

    ram(float a_Num , float b_Num)
    {
        this->a_Num = a_Num ;
        this->b_Num = b_Num ;
    }

    ram friend operator / (ram &temperary , rom &permanent); 
    ram friend operator % (ram &temperary , rom &permanent);
    void print_data();

};

class rom
{

    public :
    float m_Num , n_Num ;

    public :

    rom()
    {
        m_Num = 0;
        n_Num = 0;
    }

    rom(float m_Num , float n_Num)
    {
        this->m_Num = m_Num ;
        this->n_Num = n_Num ;
    }

    ram friend operator / (ram &temperary , rom &permanent);
    ram friend operator % (ram &temperary , rom &permanent);
    void print_data();

};

ram operator / (ram &temperary , rom &permanent)
{
    ram temp ;
    temp.a_Num = temperary.a_Num / permanent.m_Num;
    temp.b_Num = temperary.b_Num / permanent.n_Num;
    return temp ;
}

ram operator % (ram &temperary1 , rom &permanent1)
{
    ram temp1 ;
    temp1.a_Num = temperary1.a_Num % permanent1.m_Num;
    temp1.b_Num = temperary1.b_Num % permanent1.n_Num;
    return temp1 ;
}

void ram :: print_data()
{
    cout<<"values are : "<<endl;
    cout<<a_Num<<"\n"<<b_Num<<endl; 
}
void rom :: print_data()
{
    cout<<"values are : "<<endl;
    cout<<m_Num<<"\n"<<n_Num<<endl;
}
int main(int argc, char *argv[])
{
    cout<<"compiled successfully\n";
    ram ram_object(12 , 24);
    rom rom_object(2 , 4);
    
    cout<<"initial values are : "<<endl;
    ram_object.print_data();
    rom_object.print_data();

    cout<<"after overlaoding : "<<endl;
    // rom rom_object2 = ram_object / rom_object ;
    // rom rom_object3 = ram_object % rom_object ;  
    ram ram_object2 = ram_object / rom_object;
    // rom rom_object3 = ram_object % rom_object;
    
    cout<<"values after / overloading : "<<endl;
    ram_object2.print_data();

    cout<<"values after % overloading : "<<endl;
    ram_object3.print_data();

    return 0 ;
}