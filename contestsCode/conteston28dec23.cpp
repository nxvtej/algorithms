// odd one out

#include<iostream>
using namespace std;

int main() {
    int testcase = 0;
    cin>>testcase;
    while(testcase!=0) {
        int num1 , num2, num3;
        cin>>num1>>num2>>num3;
        if(num1==num2) cout<< num3;
        else if(num1==num3)cout<< num2;
        else cout<< num1;
        cout<<endl;
        testcase--;
    }
}