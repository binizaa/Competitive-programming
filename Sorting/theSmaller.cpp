/*https://usaco.org/index.php?page=viewproblem2&cpid=574*/

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
 
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
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
const ll INF = 1e17;
 
bool compara(string a, string b){
    return a + b < b + a;
}

int main(){
    int n; cin>>n;

    vector<string> words(n); rep(i,0,n) cin>>words[i];

    sort(words.begin(), words.end(),compara);

    rep(i,0,n) cout<<words[i];
    cout<<endl;

    return 0;
}