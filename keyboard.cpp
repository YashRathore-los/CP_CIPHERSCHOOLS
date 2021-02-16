#include<bits/stdc++.h>
using namespace std;
string str[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void solve(int *a, int n)
{
	int i, size;
	queue<string >q;
	for (i = 0; i < str[a[0]].size(); i++)
	{
		string s = "";
		s = s + str[a[0]][i];
		q.push(s);
	}
	i = 1;
	while (!q.empty())
	{
		if (i == n)
		{
			break;
		}
		int size = q.size();
		string s = str[a[i]];

		while (size--)
		{
			string st = q.front();
			//cout<<st<<" ";
			q.pop();
			for (int j = 0; j < s.size(); j++)
			{
				//cout<<st+s[j]<<" ";
				q.push(st + s[j]);
			}

		}
		i++;
	}
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j , n ;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = a[i] - 2;
		}
		solve(a, n);
	}
}