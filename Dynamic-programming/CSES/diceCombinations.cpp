//https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>

using ll = long long;
using vll = vector<ll>;
#define endl '\n'
#define rep(i,a,b) for(long long i = a; i < b; i++)

const long long INF = 1e9;
const int MOD = (int)1e9 + 7;
using namespace std;
 
int main() {
    long long n; cin>>n;
    
    vll dp(n+1,0);
    dp[0] = 1;
 
    rep(i,1,n+1){
        rep(j,1,7){
            if(j>i) continue;
            dp[i] = (dp[i]+dp[i-j])%MOD;
        }
    }
 
    cout<<dp[n]%MOD<<endl;
 
    return 0;
}
