#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T =0;
    cin>>T;

    while(T--)
    {
        long long int X , Y , Z ,K;
        cin>>X>>Y>>Z;

        if((Y%2==0 && Z==2) || (Z==1) || (Y==Z))
        cout<<"-1"<<endl;

        else
        {
            long long int temp;
            if(X%Y!=0)
            temp=ceil(X/Y);
            else
            temp = X/Y+1;

            while(true)
            {
                if((temp*Y)% Z !=0)
                {
                    cout<<(temp*Y)<<endl;
                    break;
                }
                else
                {
                    temp++;
                }
            }
        }

    }
    return 0;
}