/*https://codeforces.com/problemset/problem/887/C*/
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

bool ig(int a,int b,int c, int d){

    return  cubo[a] == cubo[b] && cubo[b] == cubo[c] && cubo[c] == cubo[d];
}

int main() {
    rep(i,1,25) cin>>cubo[i];

    vb cara(7,0);

    int cnt = 1;

    rep(i,1,7) {
        set<int>colour;
        rep(j,1,5){
            colour.insert(cubo[cnt++]);
        }

        if(colour.size()>2){
            cout<<"NO\n";
            return 0;
        }
        
        if(colour.size() == 1) cara[i] = 1;
    }

    bool valid = 0;

    if(cara[4] && cara[5]){

        if(ig(24,22,2,4) && ig(1,3,6,8) && ig(5,7,10,12) && ig(9,11,23,21)) valid = 1;

        if(ig(23,21,1,3) && ig(2,4,5,7) && ig(6,8,9,11) && ig(10,12,24,22)) valid = 1;
    }

    if(cara[1] && cara[3]){
        if(ig(15,16,5,6) && ig(7,8,17,18) && ig(19,20,21,22) && ig(23,24,13,14)) valid = 1;
        if(ig(13,14,7,8) && ig(5,6,19,20) && ig(17,18,23,24) && ig(21,22,15,16)) valid = 1;  
    }

    if(cara[2] && cara[6]){
        if(ig(15,13,3,4) && ig(1,2,17,19) && ig(18,20,10,9) && ig(12,11,16,14)) valid = 1;
        if(ig(16,14,1,2) && ig(3,4,18,20) && ig(17,19,12,11) && ig(10,9,15,13)) valid = 1;
    }

    if(valid)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}