/*https://codeforces.com/gym/104114/problem/N*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<int> > vvi;
typedef vector<bool> vb;

#define rep(i, a, b) for (int i = a; i < b; i++)

int n; 

int main() {
    int n, m; cin>>n>>m;

    vi arr(n+2); rep(i,1,n+1) cin>>arr[i];

    arr[0] = 0;
    arr[n+1] = 0;

    rep(i,1,n+1) arr[i] = max(arr[i], arr[i-1] - m);
    for(int i = n; i>0; i--) arr[i] = max(arr[i], arr[i+1] - m);
    
    rep(i,1,n+1) cout<<arr[i]<<' ';
    cout<<endl;

    return 0;
}
