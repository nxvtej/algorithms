#include <bits/stdc++.h> 
using namespace std;

bool check(int index, int bucketnumber, int requiredSum, 
int updatingsum, vector<int> &arr , vector<int> &picked, int K) {

    if(bucketnumber == K+1) return true;

    if(updatingsum == requiredSum) {
        return check(0, bucketnumber+1,
                requiredSum,  0, arr, picked,K);
    }
    if(index  >= arr.size()) {
        return false;
    }
    if(updatingsum > requiredSum) return false;


    if(picked[index] != 0) {
        return check(index+1, bucketnumber,
        requiredSum,  updatingsum, arr, picked, K);
    }
    else {

        // picling the item
        updatingsum+=arr[index];
        picked[index]=1;

        bool op1 = check(index+1, bucketnumber,
                requiredSum,  updatingsum, arr, picked, K);
updatingsum -= arr[index];
        picked[index] = 0;  
        bool op2 = check(index+1, bucketnumber,
                        requiredSum,  updatingsum, arr, picked, K);

        
        return op1 | op2;

    }
}
bool splitArray(vector<int> &arr, int K) {
    int totalSum =0;
    for(int i =0;i<arr.size();i++) totalSum+=arr[i];
    vector<int> picked(arr.size(),0);
    if(totalSum % K != 0) return false;
    int requiredSum = totalSum/K;
    return check(0,1,requiredSum,0,arr,picked,K);

}