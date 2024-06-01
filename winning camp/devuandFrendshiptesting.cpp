#include <iostream>
#include <set>
#include <vector>
using namespace std;
void solve() {
    int n=0;
    cin>>n;
    set<int> s;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
            cin>>v[i];
            s.insert(v[i]);
    }
    int ans = s.size();
    cout<<ans<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}