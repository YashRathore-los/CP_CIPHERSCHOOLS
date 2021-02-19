#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>v = {1, 3, 0, 2, 5};
	int n = v.size();
	vector<int>ans(n);
	stack<int>s;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(v[i]);
			ans[i] = -1;
		}
		else {
			if (s.top() < v[i]) {
				ans[i] = s.top();
				s.push(v[i]);
			}
			else {
				while (!(s.empty() || s.top() < v[i])) {
					s.pop();
				}
				if (s.empty()) {
					ans[i] = -1;
					s.push(v[i]);
				}
				else {
					ans[i] = s.top();
					s.push(v[i]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}