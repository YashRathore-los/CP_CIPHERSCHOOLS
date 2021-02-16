#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;
int fib(int n) {
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}
int fact(int n) {
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}
int32_t main() {
#ifndef ONLINE_JUDGE
	/* code */
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 5;
	cout << fib(n) << endl;
	cout << fact(n);
}