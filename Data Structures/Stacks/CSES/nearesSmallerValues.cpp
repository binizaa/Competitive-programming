/*https://cses.fi/problemset/task/1645/*/
#include <iostream>
#include <stack>
#include <vector>

#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

int main(){
    int n; cin>>n;

    vector<int> arr(n); rep(i,0,n) cin>>arr[i];

    stack<int> st;

    rep(i,0,n){
        
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        if(st.empty()) cout<<0<<" ";
        else cout<<st.top() + 1<<" ";

        st.push(i);
    }
    cout<<endl;
    return 0;
}