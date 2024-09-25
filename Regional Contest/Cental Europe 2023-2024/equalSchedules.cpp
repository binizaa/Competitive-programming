/*https://codeforces.com/gym/104871/problem/E*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <map>

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

struct person{
    int s, e;
    string name;
};

bool comp (const person& a, const person& b){
    return  a.name < b.name;
}

int main(){
    vector<person> sh1;
    vector<person> sh2;
    string linea;

    while(getline(cin, linea)){

        if(linea == "------") break;
        
        stringstream ss(linea);

        person p;
        ss >> p.s >> p.e >> p.name;

        sh1.pb(p);
    }

    while(getline(cin, linea)){

        if(linea == "======") break;
        
        stringstream ss(linea);

        person p;
        ss >> p.s >> p.e >> p.name;

        sh2.pb(p);
    }

    map<string,int> map1;
    map<string, int> map2;
    set<string> names;

    rep(i,0,sh1.size()){
        map1[sh1[i].name] += (sh1[i].e - sh1[i].s);
        names.insert(sh1[i].name);
    }

    rep(i,0,sh2.size()){
        map2[sh2[i].name] += (sh2[i].e - sh2[i].s);
        names.insert(sh2[i].name);
    }

    map<string,int>::iterator css;

    set<string>::iterator itr;

    vector<person> diff;

    for (itr = names.begin(); itr != names.end(); itr++){
        person p;
        p.name = *itr;
        p.s = map2[*itr] - map1[*itr];
        diff.push_back(p);
    }

    sort(diff.begin(),diff.end(), &comp);

    bool exist = true;

    rep(i,0,diff.size()){
        if(diff[i].s == 0) continue;

        exist = false;
        cout<<diff[i].name<<" ";

        if(diff[i].s > 0) cout<<"+";
        cout<<diff[i].s<<endl;
    }

    if(exist) cout<<"No differences found."<<endl;

}