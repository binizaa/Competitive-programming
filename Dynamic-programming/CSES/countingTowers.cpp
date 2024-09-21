/*https://cses.fi/problemset/task/2413*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
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
const ll INF = 1e18;
 
int main() {
    int t; cin>>t;

    vll arr(t); 
 
    ll maxi = 0;
    
    rep(i,0,t){
        cin>>arr[i];
        maxi = max(maxi,arr[i]);
    }
 
    vll c1(maxi+1);
    vll c2(maxi+1);
 
    c1[1] = 1;
    c2[1] = 1;
 
    rep(i,2,maxi+1){
        c1[i] = (c1[i-1] + c2[i-1] + c1[i-1])%MOD;
        c2[i] = (c1[i-1] + c2[i-1] + c2[i-1] * 2 + c2[i-1])%MOD;
    }
 
    rep(i,0,t){
        cout<<(c1[arr[i]]+c2[arr[i]])%MOD<<endl;
    }
 
    return 0;
}