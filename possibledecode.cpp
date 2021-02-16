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
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> s;
		n = s.size();
		if (s[0] == '0') {
			cout << 0 << endl;
			continue;
		}
		int dp[n + 1];
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = 0;
			if (s[i - 1] != '0') {
				dp[i] = dp[i - 1];
			}
			if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
				dp[i] += dp[i - 2];
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}