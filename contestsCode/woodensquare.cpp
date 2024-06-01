#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
bool possibletoconstruct (vector<int> &buckets) {
 int totalsquare =0;
 for(int squares:buckets) {
    totalsquare+=squares;
 }
 int issquare = sqrt(totalsquare);
 return issquare*issquare == totalsquare;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n , l;
        cin>> n;
        if(n==0) cout<<"no\n";
        vector<int> numbucket(n);
        for(int i=0;i<n;i++) {
            cin>>numbucket[i];
        }

        if(possibletoconstruct(numbucket)) {
            cout<<"yes"<<endl;
        }
        else cout <<"no"<<endl;
        

    }
    return 0;
}