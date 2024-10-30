/*https://usaco.org/index.php?page=viewproblem2&cpid=574*/

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
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
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
 
int z, a, b; 
vi val;

vb maxDP(int n){
    vb dp(n+1,0);

    dp[0] = 1;

    rep(i,1,n+1){
        rep(j,0,2){
            if(i - val[j] < 0) continue;

            if(dp[i - val[j]]){
                dp[i] = 1;
            }
        }
    }

    return dp;
}

int main(){
    freopen("feast.in", "r", stdin); 
    freopen("feast.out", "w", stdout); 

    cin>>z>>a>>b;
    val.push_back(a);
    val.push_back(b);

    vb dp = maxDP(z);

    vi prefix(z+1);
    prefix[0] = 0;

    rep(i,1,z+1){
        if(dp[i]) prefix[i] = i;
        else prefix[i] = prefix[i-1];
    }

    int maxi = 0;

    rep(i,0,z+1){
        if(!dp[i]){
            continue;
        }

        int aux = prefix[z - floor(i/2)] + floor(i/2);
        maxi = max(maxi, aux);
    }

    cout<<maxi<<endl;

    return 0;
}