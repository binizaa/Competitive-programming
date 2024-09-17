/*https://codeforces.com/problemset/problem/1972/B*/
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

void solve(){
    int n; cin>>n;
    string str; cin>>str;

    int cnt = 0;

    for(char c:str) if(c=='U') cnt++;

    if(cnt%2==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main(){
    int t; cin>>t;

    while(t--) solve();

    return 0;
}