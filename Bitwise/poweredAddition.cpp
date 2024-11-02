/*https://codeforces.com/contest/1338/problem/A*/

#include <iostream>
#include <bit>
#include <vector>
using namespace std;


typedef long long ll;
typedef vector<ll> vi;

#define rep(i,a,b) for(int i= a; i<b;i++)

/*
If x is not zero, calculates the number of bits needed to store the value x, that is, 
1 + ⌊ log2 (x) ⌋. If x is zero, returns zero.
*/

int bit_width(int x) {
    int width = 0;
    while (x > 0) {
        x >>= 1;
        width++;
    }
    return width;
}

void solve(){
    int n; cin>>n;

    vi arr(n); 
    rep(i,0,n) cin>> arr[i];

    int ans = 0;

    rep(i,1,n){
        if(arr[i]<arr[i-1]){
            unsigned int diff = arr[i-1] - arr[i];
            ans = max(ans, bit_width(diff));
            arr[i] = arr[i-1];
        }
    }

    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;

    rep(i,0,t) solve();

    return 0;
}