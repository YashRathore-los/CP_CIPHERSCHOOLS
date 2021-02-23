class Solution {
public:
	int min(int a, int b, int c)
	{
		if (a < b && a < c) return a;
		else if (b < a && b < c) return b;
		else
			return c;
	}
	int minDistance(string word1, string word2)
	{
		int n1 = word1.size();
		int n2 = word2.size();
		int dp[n1 + 1][n2 + 1];
		for (int i = 0; i < n1 + 1; i++)
		{
			for (int j = 0; j < n2 + 1; j++)
			{
				if (i == 0)
					dp[i][j] = j; // initialiation dhayan se as ek string empty hai and
				if (j == 0) // other is non-empty then min. opeartion = length of
					dp[i][j] = i; // that non-empty string
			}
		}
		for (int i = 1; i < n1 + 1; i++)
		{
			for (int j = 1; j < n2 + 1; j++)
			{
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min((1 + dp[i][j - 1]), (1 + dp[i - 1][j]), (1 + dp[i - 1][j - 1]));
			}
		}
		return dp[n1][n2];
	}
};