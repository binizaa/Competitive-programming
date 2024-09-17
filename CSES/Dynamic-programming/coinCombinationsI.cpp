/*https://cses.fi/problemset/result/8936706/*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <math.h>
using ll = long long;
using vi = vector<long long>;
#define endl '\n'
#define rep(i,a,b) for(long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define lb(v,a) lower_bound(v.begin(),v.end(),a)-v.begin()
#define ub(v,a) upper_bound(v.begin(),v.end(),a)-v.begin()-1
const long long INF = 1e9;
const int MOD = (int)1e9 + 7;
using namespace std;
 
int main() {
    long long x, n; cin>>x>>n;
	vi arr(x); rep(i,0,x) cin>>arr[i];
    
    vi dp(n+1,0);
    dp[0] = 1;
 
    rep(i,1,n+1){
        rep(j,0,x){
            if(arr[j]>i) continue;
            dp[i] = (dp[i]+dp[i-arr[j]])%MOD;
        }
    }
 
    cout<<dp[n]%MOD<<endl;
 
    return 0;
}