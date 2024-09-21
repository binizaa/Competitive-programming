/*https://cses.fi/problemset/task/1638*/

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
const ll INF = 1e17;
 
int main(){
   ll n; cin>>n;
 
    vector<vector<char>> matrix(n+1,vector<char> (n+1));
    vvll sum(n+1,vll(n+1,0));
 
    rep(i,1,n+1) rep(j,1,n+1) cin>>matrix[i][j];
 
    if(matrix[1][1] == '*'){
        cout<<0<<endl;
        return 0;
    }
 
    bool valid1 = false, valid2 = false;
    
    rep(i,1,n+1){
        if(matrix[1][i] == '*' || valid1){
            sum[1][i] = 0;
            valid1 = true;
        } else sum[1][i] = 1;

        if(matrix[i][1] == '*' || valid2){
            sum[i][1] = 0;
            valid2 = 1;
        } else sum[i][1] = 1;
    }
 
    rep(i,2,n+1){
        rep(j,2, n+1){
            if(matrix[i][j] == '*') sum[i][j] = 0;
            else sum[i][j] = sum[i-1][j]%MOD + sum[i][j-1]%MOD; 
        }
    }
 
    cout<<sum[n][n]%MOD;
}
