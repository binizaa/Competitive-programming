#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;

typedef pair<ll,ll> pll;
typedef pair<int, int> pii;


#define pb(x) push_back(x)
#define mkp(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>b; i--)
#define all(x) (x).begin(), (x).end()

ll MOD = 1e9 + 7;
const ll INF = 1e17;

int main(){
    int n; cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));

    vector<vector<int>> dp(n,vector<int>(3,0));

    rep(i,0,n) rep(j,0,3) cin>>arr[i][j];

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    rep(i,0,n-1){
        rep(j,0,3){
            rep(k,0,3){
                if(j==k) continue;
                dp[i+1][k] = max(dp[i+1][k], dp[i][j] + arr[i+1][k]);
            }
        }
    }

    int maxi = 0;

    rep(i,0,3) maxi = max(maxi, dp[n-1][i]);

    cout<<maxi<<endl;
}