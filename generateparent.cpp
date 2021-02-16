#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;
void gpp(std::vector<string> &ans, int op, int cp, int n, string curr) {
	if (op == n && cp == n) {
		ans.push_back(curr);
		return;
	}
	if (op < n) {
		gpp(ans, op + 1, cp, n, curr + '(');
	}
	if (cp < op) {
		gpp(ans, op, cp + 1, n, curr + ')');
	}
	return;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	std::vector<string> ans;
	gpp(ans, 0, 0, n, "");
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;

}