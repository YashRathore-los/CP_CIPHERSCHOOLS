#include <bits/stdc++.h>
using namespace std;


vector<string> Result;
void getPath(int m[MAX][MAX], int i, int j, int n, string path)
{
    if (i == n - 1 && j == n - 1)
    {
        Result.push_back(path);
        return;
    }

    if (i - 1 >= 0 && m[i - 1][j] == 1)
    {
        m[i - 1][j] = 0;
        getPath(m, i - 1, j, n, path + "U");
        m[i - 1][j] = 1;
    }
    if (i + 1 < n && m[i + 1][j] == 1)
    {
        m[i + 1][j] = 0;
        getPath(m, i + 1, j, n, path + "D");
        m[i + 1][j] = 1;
    }

    if (j - 1 >= 0 && m[i][j - 1] == 1)
    {
        m[i][j - 1] = 0;
        getPath(m, i, j - 1, n, path + "L");
        m[i][j - 1] = 1;
    }

    if (j + 1 < n && m[i][j + 1] == 1)
    {
        m[i][j + 1] = 0;
        getPath(m, i, j + 1, n, path + "R");
        m[i][j + 1] = 1;
    }
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    Result.clear(); m[0][0] = 0; getPath(m, 0, 0, n, "");
    sort(Result.begin(), Result.end());
    return Result;
}