#include <bits/stdc++.h>
using namespace std;

void factorial(int n)
{
    // Write your code here
    vector<int> res;
    res.push_back(1);
    // int res_size=1;

    for(int x=2;x<=n;x++){
        int car =0;

        for(int i =0;i<res.size();i++){
            int val = res[i]*x+car;
            res[i]=val%10;
            car=val/10;
        }
        while(car){
            res.push_back(car%10);
            car=car/10;
            // res_size++;
        }
    }
     for (int i = res.size() - 1; i >= 0; i--)
             cout << res[i];
}

int main(){
    factorial(5);
    return 0;
}