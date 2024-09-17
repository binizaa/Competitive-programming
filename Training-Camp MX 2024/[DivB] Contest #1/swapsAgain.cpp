/*https://codeforces.com/problemset/problem/1365/F*/
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

void resolve(){
    int n; cin>>n;

    vll a(n); rep(i,0,n) cin>>a[i];
    vll b(n); rep(i,0,n) cin>>b[i];

    if(n%2==1 && a[n/2] != b[n/2]){
        cout<<"no"<<endl;
        return;
    }

    vector<pll> ap(n), bp(n);

    rep(i,0,n){
        ap[i] = make_pair(min(a[i],a[a.size()-1-i]), max(a[i],a[a.size()-1-i]));
        bp[i] = make_pair(min(b[i],b[b.size()-1-i]), max(b[i],b[b.size()-1-i]));
    }

    sort(all(ap));
    sort(all(bp));

    rep(i,0,n){
        if(ap[i].first!=bp[i].first || ap[i].second != bp[i].second){
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;
}

int main(){
    int t; cin>>t;

    while(t--) resolve();
    return 0;
}