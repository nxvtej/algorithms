    #include <string.h>
    #include <iostream>
    using namespace std;

    class bache 
    {
        private :
        int error_number; // for the count of errors that occur ;
        string error_message; // for the message which is to be displayed

        public :
        bache()
        {}

        bache (int error_number , string error_message)
        {
            this->error_number = error_number;
            this->error_message = error_message;
            // strcpy(error_message , this->error_message);
        }

        float division ( int num_1 , int num_2 )
        {
            if(num_2 == 0 )
            throw bache(001,"BACHE MASTI NHI \n");

            else
            return (float)num_1/num_2;
        }

        void display()
        {
            cout<<"ARE YAR YE TO ERROR AAGYA \n";
            cout<<"ERROR : "<<error_number<<endl;
            cout<<"ERROR MESSAGE : "<<error_message<<endl;
        }
    };
    int main(void)
    {
        cout<<"HELLO BACHE\n";
        cout<<"enter your first number : ";
        int num_1{} , num_2{} ;
        cin>>num_1 ; 

        // cout<<endl;

        cout<<"enter your second number : ";
        cin>>num_2 ;

        // cout<<endl;

        bache budhe ;
        try
        {
            /* code */
            float div = budhe.division(num_1, num_2);
            cout<<"Division of number : "<<num_1<<" and "<<num_2<<" : "<<div<<endl;
        }
        catch(bache &budhe_no_1)
        {
            budhe.display();
        }
}