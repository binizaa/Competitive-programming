/*https://cses.fi/paste/87e1676053ff69a58e5b8b/*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <math.h>
#include <map>
#include <iomanip>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ll>> vvi;
typedef vector<bool> vb;
 
typedef set<ll> sll;
typedef pair<ll,ll> pll;
typedef pair<ll, ll> pii;
typedef pair<string, string> pss;
 
#define pb(x) push_back(x)
#define mkp(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
 
ll MOD = 1e9 + 7;
const ll INF = 1e17;
 
vvll nums(ll length, ll l, ll m){
    vvll dp(101,vll(length+1,0));
    
    dp[l-1][1] = dp[l][1] = dp[l+1][1] = 1;
 
    rep(i,2,length+1){
        rep(j,1,m+1){
            if(j != 1) dp[j][i] += dp[j-1][i-1]; //sum of the previous
            dp[j][i] += dp[j][i-1];
            if(j != m) dp[j][i] += dp[j+1][i-1]; //sum of the following
        }
    }
 
    rep(j,1,m+1) { 
        rep(i,1,length+1) cout<<dp[j][i]<<" ";
        cout<<endl;
    }
 
    return dp;
}
 
int main(){
    ll n, m; cin>>n>>m;
 
    vll array(n); rep(i,0,n) cin>>array[i];
 
    vvll dp(n,vll(m+2,0));
 
    rep(i,0,n){
 
        if(i==0){
            if(array[0] == 0) rep(i,1,m+1) dp[0][i] = 1;
            else dp[0][array[i]] = 1;
            continue;
        }
 
        if(array[i] == 0){
            rep(j,1,m+1){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j + 1])%MOD;
            }
        }else{
            dp[i][array[i]] = (dp[i - 1][array[i] - 1] + dp[i - 1][array[i]] + dp[i - 1][array[i] + 1])%MOD;
        }
    }
    
    ll total = 0;
 
    rep(i,1,m+1) total = (total + dp[n-1][i]) % MOD;
 
    cout<<total<<endl;
    return 0;
}