int dp[m][n];
memset(dp, 0, sizeof(dp));

dp[0][0] = grid[0][0];
for (int i = 1; i < m; i++)
    dp[i][0] += grid[i][0] + dp[i - 1][0];    //initialize 1st column

for (int i = 1; i < n; i++)
    dp[0][i] += grid[0][i] + dp[0][i - 1];    //initialize 1st row

for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++) {
        dp[i][j] += min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]); //find minimum of top and left distance costs
    }
return dp[m - 1][n - 1];
}
};