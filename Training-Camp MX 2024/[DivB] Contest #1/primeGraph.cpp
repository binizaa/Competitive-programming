/*https://codeforces.com/problemset/problem/1178/D*/
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

vb isPrime;
vector<int> primes;

void criba(int n){
    isPrime = vector<bool>(n,true);
    primes = vector<int>();
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<n; ++i){
        if(isPrime[i]){
            primes.push_back(i);
            for(int h =2; h*i<n; ++h) isPrime[i*h] = 0;
        }
    }
}

vector<pll> edges;

void conCiclo(int n){
    rep(i,1,n) edges.push_back(make_pair(i,i+1));
    edges.push_back(make_pair(n,1));
}

int main(){
    int n; cin>>n;

    conCiclo(n);

    criba(n + n/2);

    if(isPrime[n]){
        cout<<edges.size()<<endl;
        for(auto a : edges) cout<<a.first<<" "<<a.second<<endl;
        return 0;
    }
    
    auto upper = upper_bound(all(primes), n);

    ll nums = *upper;

    ll mitad = n/2;

    nums -= n;

    for(int i = 1; i<=nums; i++){
        edges.pb(make_pair(i, i+mitad));
    }

    cout<<edges.size()<<endl;

    for(auto a : edges) cout<<a.first<<" "<<a.second<<endl;
    
    return 0;
}