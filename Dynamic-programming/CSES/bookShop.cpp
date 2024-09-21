/*https://cses.fi/paste/2a702d25ffca8e3d8dafbf/*/

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
 
int main(){
    int n, x; cin>>n>>x;
 
    vll price(n+1); rep(i,1,n+1) cin>>price[i];
    vll pages(n+1); rep(i,1,n+1) cin>>pages[i];
 
    vll dp(x+1,0);
 
    dp[0] = 0;
    
    rep(i,1,n+1){
        per(w, x,1){
            if(price[i] <= w)
                dp[w] = max(dp[w], pages[i] + dp[w - price[i]]);
        }
    }
 
    cout<<dp[x]<<endl;
 
   return 0;
}