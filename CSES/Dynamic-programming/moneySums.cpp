/*https://cses.fi/problemset/task/1745/*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
    ll n, sum_max = 0;
    cin >> n;
    
    vll coins(n);
    for(ll i = 0; i < n; i++) {
        cin >> coins[i];
        sum_max += coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum_max + 1, 0));
    dp[0][0] = true;

    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= sum_max; j++) {
            dp[i][j] = dp[i-1][j];
            ll anterior = j - coins[i-1];
            if (anterior >= 0 && dp[i-1][anterior]) {
                dp[i][j] = true;
            }
        }
    }

    vll nums;
    for(ll i = 1; i <= sum_max; i++) {
        if(dp[n][i]) nums.push_back(i);
    }

    cout << nums.size() << endl;
    for(ll num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
