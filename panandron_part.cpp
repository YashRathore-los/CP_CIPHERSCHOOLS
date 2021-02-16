#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define len(s) int(s.length())

void allPalPartUtil(string res, int n, string str)
{
    for (int i = 1; i <= n; ++i)
    {
        string x = str.substr(0, i);
        string y = x;
        reverse(all(x));
        if (x == y) {
            if (i == n) {
                cout << res + x << endl;
                return;
            }
            allPalPartUtil(res + x + " ", n - len(x), str.substr(i));
        }
    }
}

int main()
{
    string str = "nitin";
    allPalPartUtil("", len(str), str);
    return 0;
}