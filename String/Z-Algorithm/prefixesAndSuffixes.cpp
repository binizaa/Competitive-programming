#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<int> z_function(const string &s) {
    vector<int> z(s.size());
    z[0] = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string str;
    cin >> str;

    int n = str.size();
    vector<int> z = z_function(str);
    
    vector<int> count(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        if (z[i] > 0) {
            count[z[i]]++;
        }
    }

    for (int i = n - 1; i > 0; i--) {
        count[i] += count[i + 1];
    }
    
    count[n] = 1;

    vector<pair<int, int>> result;
    for (int i = 1; i <= n; i++) {
        if (z[n - i] == i) {
            result.push_back({i, count[i]});
        }
    }

    cout << result.size() << endl;
    for (auto &p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
