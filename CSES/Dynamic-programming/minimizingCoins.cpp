/*https://cses.fi/problemset/result/8905534/*/
 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <math.h>
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define endl '\n'
#define rep(i,a,b) for(int i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define lb(v,a) lower_bound(v.begin(),v.end(),a)-v.begin()
#define ub(v,a) upper_bound(v.begin(),v.end(),a)-v.begin()-1
const int INF = 1e9;
const int MOD = (int)1e9 + 7;
using namespace std;
 
 
int main() {
	int n, x; cin >> n >> x;
	vi coins(n);
    vi dp(x+1,INF);
 
	for (int i = 0; i < n; i++) cin >> coins[i]; 

    dp[0] = 0;
	
	rep(i,1, x+1) {
		rep(j, 0,n) {
			if (i - coins[j] >= 0) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
		}
	}
 
    if(dp[x] == INF) cout<<-1<<endl;
    else cout<<dp[x]<<endl;
}