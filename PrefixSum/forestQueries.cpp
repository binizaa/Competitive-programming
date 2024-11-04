/*https://cses.fi/problemset/task/1652/*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;

#define rep(i, a, b) for (ll i = a; i < b; i++)

struct querry{
    int x1,y1,x2,y2;
};

int main() {
    int n, m; cin>>n>>m;

    vector<string> matrix(n);
    rep(i,0,n)cin>>matrix[i];

    vector<querry> querrys(m);
    rep(i,0,m){
        cin >> querrys[i].x1 >> querrys[i].y1 >> querrys[i].x2 >> querrys[i].y2;
    }

    vvi prefix2D(n+1,vi(n+1,0));

    rep(i,1,n+1){
        rep(j,1,n+1){
            int val = matrix[i-1][j-1]=='*' ? 1:0; 
           prefix2D[i][j] = prefix2D[i-1][j] + prefix2D[i][j-1] - prefix2D[i-1][j-1] + val;
        }
    }

    /*rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<prefix2D[i][j]<<' ';
        }
        cout<<endl;
    }*/

    rep(i,0,m){
        int x1 = querrys[i].x1, y1 = querrys[i].y1, x2 = querrys[i].x2, y2 = querrys[i].y2;
        int cnt = prefix2D[x2][y2] - prefix2D[x1-1][y2] - prefix2D[x2][y1-1] + prefix2D[x1-1][y1-1];
        cout<<cnt<<endl;
    }

    return 0;
}
