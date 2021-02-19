#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

bool solve(string p) {
	stack<char>s;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == ')') {
			if (s.empty()) {
				return false;
			}
			else if (s.top() == '(') {
				return false;
			}
			else {
				while (!(s.empty() || s.top() == '(')) {
					s.pop();
				}
				if (s.empty()) {
					return false;
				}
				s.pop();
			}
		}
		else {
			s.push(p[i]);
		}
	}
	return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s = "((a+b)+(c+d))";
	if (solve(s))
		cout << "false";
	else
		cout << "true";
	return 0;
}