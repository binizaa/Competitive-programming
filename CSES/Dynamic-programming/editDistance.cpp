/*https://cses.fi/problemset/task/1639*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
 
#define rep(i, a, b) for (ll i = a; i < b; i++)
 
int main() {
    string a, b; cin >> a >> b;

    int n = a.size(), m = b.size();
 
    vvll dp(n + 1, vll(m + 1));
 
    rep(i, 0, n + 1) {
        rep(j, 0, m + 1) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1]; 
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])); 
        }
    }
 
    cout << dp[n][m] << endl; 
 
    return 0;
}