#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define sort(a) sort(a.begin(),a.end())
#define endl '\n'
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
using namespace std;
void push(stack<int>&s, int x, int &min) {
	if (s.empty()) {
		min = x;
		s.push(x);
		return;
	}
	if (x >= min) {
		s.push(x);
	}
	else {
		s.push((2 * x) - min);
		min = x;
	}
	return;
}

void pop(stack<int>&s, int &min) {
	if (s.empty()) {
		return;
	}
	if (s.top() >= min) {
		s.pop();
	}
	else {
		min = (2 * min) - s.top();
		s.pop();
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
	stack<int>s;
	int min = 0;
	push(s, 3, min);
	push(s, 4, min);
	push(s, 5, min);
	push(s, 1, min);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

}