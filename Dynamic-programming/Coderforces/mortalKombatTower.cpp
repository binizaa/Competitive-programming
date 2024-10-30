/*https://codeforces.com/problemset/problem/1418/C?csrf_token=fe6ad464e7a7bd86b216dfa59bdd5c5d*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<ll> > vvi;
typedef vector<bool> vb;

typedef pair<ll,ll> pll;
typedef pair<ll, ll> pii;


#define pb(x) push_back(x)
#define mkp(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>b; i--)
#define all(x) (x).begin(), (x).end()

ll MOD = 1e9 + 7;
const ll INF = 1e17;

void solve(){
    int n; cin>>n;

    vi arr(n); rep(i,0,n) cin>> arr[i];

    if (n == 1) {
        cout << (arr[0] == 1 ? 1 : 0) << endl;
        return;
    }

    vvi dp(n, vi(2, INF));

    if (arr[0] == 1) dp[0][0] = 1;
    else dp[0][0] = 0;

    if (arr[1] == 1) dp[1][0] = 1+dp[0][0];
    else dp[1][0] = dp[0][0];

    dp[0][1] = INF; 
    dp[1][1] = dp[0][0];

    rep(i,2,n){
        dp[i][0] = arr[i]+min(dp[i-1][1], arr[i-1]+dp[i-2][1]); 
        dp[i][1] = min(dp[i-1][0], dp[i-2][0]);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}

int main(){
    int t; cin>>t;

    while(t--) solve();
}