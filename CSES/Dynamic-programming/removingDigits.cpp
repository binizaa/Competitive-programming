/*https://cses.fi/problemset/task/1637/*/

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
 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
 
#define pb(x) push_back(x)
#define mkp(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define per(i,a,b) for(ll i=a; i>=b; i--)
#define all(x) (x).begin(), (x).end()
 
ll MOD = 1e9 + 7;
const ll INF = 1e17;
 
int main() {
    int n; cin>>n;
 
    vi arr(n+1,1e9);
 
    arr[0] = 0;
 
    rep(i,1, n+1){
        int num = i;
        while(num > 0){
            arr[i] = min(arr[i - (num%10)] + 1, arr[i]);
            num = num/10;
        }
    }
 
    cout<<arr[n]<<endl;
 
    return 0;
}