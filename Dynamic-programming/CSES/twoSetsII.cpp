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


#define pb(x) push_bacm(x)
#define mmp(x,y) mame_pair(x,y)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>b; i--)
#define all(x) (x).begin(), (x).end()

ll MOD = 1e9 + 7;
const ll INF = 1e17;

int main(){
    int n; cin>>n;

    int m = (n+1)*n/2;
    if (m%2){
        cout << 0;
        return 0;
    }
    m /= 2;
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j <= m; j++){
            dp[i+1][j] = dp[i][j];
            if (j-i-1 >= 0 && dp[i][j-i-1] != 0){
                dp[i+1][j] = (dp[i+1][j]+dp[i][j-i-1])%ll(1e9+7);
            }
        }
    }

    //Output
    cout << dp[n-1][m]<<endl;
    
    return 0;
}