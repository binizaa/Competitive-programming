/*https://codeforces.com/problemset/problem/1025/C*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

int main(){
    string s; cin>>s;

    s += s;

    int cnt = 1, maxi = 0;

    rep(i,0,s.size()-1){
        if(s[i] == s[i+1]){
            maxi = max(maxi, cnt);
            cnt = 1;
        }else cnt++;
    }

    maxi = max(maxi,cnt);

    if(maxi == s.size())cout<<maxi/2<<endl;
    else cout<<maxi<<endl;
    
}