#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;

void reverse(stack<int>&s, int temp) {
	if (s.empty()) {
		s.push(temp);
	}
	else {
		if (temp >= s.top()) {
			s.push(temp);
		}
		else {
			int temp1 = s.top();
			s.pop();
			reverse(s, temp);
			s.push(temp1);
		}
	}

}
void solve(stack<int>&s) {
	if (!s.empty()) {
		int temp = s.top();
		s.pop();
		solve(s);
		reverse(s, temp);
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
	stack<int>s;
	s.push(30);
	s.push(-5);
	s.push(18);
	s.push(14);
	s.push(-3);

	solve(s);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}