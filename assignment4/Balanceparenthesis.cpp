#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

bool solve(string s){
	stack<int>s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] || == '[') {
			s.push(s[i]);
		}
		else {
			if (s.empty()) {
				return false;
			}
		}
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "";
	if (solve(s) {
	cout << "Yes";
}
else {
	cout << "NO";
}
}