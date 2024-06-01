#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve() {
    long long int n;
    cin>>n;
    
    map<ll, ll> freq;
    
    for(long long int i = 0; i<n; i++){
        long long int type = 0;
        cin>>type;
        
        freq[type]++;
    }
    for(auto it:freq) {
        int key = it.first;
        int occurance = it.second;
        if(occurance %2==1)
        {
            cout<<key<<endl; 
            return;
        }
    }
}
int main() {
	int testcase =0;
	cin>>testcase;
    for(int i=0;i<testcase;i++) solve();
    return 0;
}
