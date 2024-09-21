/*https://cses.fi/problemset/task/1744*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
 
#define rep(i, a, b) for (ll i = a; i < b; i++)
 
int main() {
    int a,b; cin>>a>>b;
 
    vvll dp(a+1,vll(b+1,1e9));
 
    rep(i,1,a+1){
        rep(j,1,b+1){
            if(i == j) dp[i][j] = 0;
            else{ //minimum
                rep(h,1,j){
                    dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j-h] + 1);
                }
 
                rep(k,1,i) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
 
            }
        }
    }

    cout<<dp[a][b]<<endl;
 
    return 0;
}
