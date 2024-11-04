/*https://atcoder.jp/contests/abc125/tasks/abc125_c*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;

#define rep(i, a, b) for (ll i = a; i < b; i++)

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vi prefixGCD(n), suffixGCD(n);

    prefixGCD[0] = arr[0];
    rep(i, 1, n) prefixGCD[i] = gcd(prefixGCD[i - 1], arr[i]);

    suffixGCD[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) suffixGCD[i] = gcd(suffixGCD[i + 1], arr[i]);

    /*rep(i, 0, n) cout << prefixGCD[i] << ' ';
    cout << endl;
    rep(i, 0, n) cout << suffixGCD[i] << " ";
    cout << endl;*/

    int maxGCD = 0;
    rep(i, 0, n) {
        if (i == 0) {
            maxGCD = max(maxGCD, suffixGCD[1]);
        } else if (i == n - 1) {
            maxGCD = max(maxGCD, prefixGCD[n - 2]);
        } else {
            maxGCD = max(maxGCD, gcd(prefixGCD[i - 1], suffixGCD[i + 1]));
        }
    }

    cout << maxGCD << endl;

    return 0;
}
