/*https://cses.fi/problemset/task/1732*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <map>
#include <cmath>

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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    string s; cin>>s;
    vi pi = prefix_function(s);

    int j = pi[s.size()-1];

    vi ans;
    while(j> 0){
        ans.push_back(j);
        j = pi[j-1]; 
    }

    //sort(all(ans));

    rep(i,0,ans.size()) cout<<s.size()-ans[i]<<" ";
    cout <<s.size()<< endl;
}