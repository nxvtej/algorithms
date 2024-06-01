#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve() {
    ll n;
    cin>>n;
    map<ll,ll> freq;
    while(n--) {
        int aa=0;
        cin>>aa;
        freq[aa]++;
    }
    vector<int>res; 
    for(auto it:freq) res.push_back(it.second);
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    if(res[0]!=res[1])cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return;
}
int main() {
	// your code goes here
    ll testcase;
    cin>>testcase;
    
    while(testcase--) solve();
    return 0;
}
