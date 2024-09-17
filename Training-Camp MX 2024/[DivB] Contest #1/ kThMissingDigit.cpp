/*https://codeforces.com/problemset/gymProblem/102218/K*/
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
vector<int>cubo(25);

int main() {
    
    ll a,b,p; cin>>a>>b>>p;

    string A,B,C; cin>>A>>B>>C;

    ll intA = 0,intB = 0,intC = 0;

    rep(i,0,a) intA += A[i] - '0';
    intA = intA%9;
    
    rep(i,0,b) intB += B[i] - '0';
    intB = intB%9;

    ll mult = (intA * intB)%9;

    rep(i,1,10){
        ll intC = 0;
        rep(j,0,p){
            if(C[j]=='*') intC += i;
            else intC += C[j] - '0';
        }
        intC = intC%9;

        if(intC == mult){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}