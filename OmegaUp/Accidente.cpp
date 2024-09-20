/*https://omegaup.com/arena/problem/Accidente/*/
#include <iostream>
#include <vector>

typedef long long ll;
typedef long double ld;

typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<std::vector<ll>> vvll;

#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

void solve(string str){
    // Find '-'
    int count = 0;
    int current = 0, front = 0;
    rep(i, 0, str.size()){
        if(str[i] == '-'){
            front++;
            count++;
        } else break;
    }

    int max_value = front, balance = 0;

    rep(i, count, str.size()){
        if(str[i] == '+'){
            balance++;
            if(front > 0) front--;
            max_value = max(max_value, balance);
        } else {
            if(balance > 0){
                balance--;
                front++;
            } else {
                front++;
                max_value++;
            }
        }
    }

    cout << max_value << endl;
}

int main() {
    string line;
    
    while (getline(cin, line)) {
        if (!line.empty()) {
            solve(line);
        }
    }

    return 0;
}
