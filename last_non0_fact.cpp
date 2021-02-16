#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while (t--)
	{
		int n, cnt = 0;
		cin >> n;
		vector<unsigned long long int>v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			while (v[i] && v[i] % 5 == 0)
			{
				v[i] = v[i] / 5;
				cnt++;
			}
		}
		unsigned long long int ans = 1;
		for (int i = 0; i < n; i++)
		{
			while (cnt && v[i] && v[i] % 2 == 0)
			{
				v[i] = v[i] / 2;
				cnt--;
			}
		}
		for (int i = 0; i < n; i++)
		{
			ans = (ans * (v[i] % 10)) % 10;
		}
		if (cnt)
		{
			ans = (ans * 5) % 10;
		}
		if (ans)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}