/*https://judge.yosupo.jp/problem/zalgorithm*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> z_function(const string &s) {
	vector<int> z(s.size());
	z[0] = s.size();

	int l = 0;
	int r = 0;
	for (int i = 1; i < s.size(); i++) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
			l = i;
			r = i + z[i];
			z[i]++;
		}
	}

	return z;
}

int main() {
	string s;
	cin >> s;
	vector<int> z = z_function(s);
	for (int i = 0; i < s.size(); i++) {
		cout << z[i] << " "; 
	}
}