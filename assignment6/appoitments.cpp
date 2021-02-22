class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        if (v.size() < 2) return 0;

        int count = 0;

        sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int i = 0, j = 1;
        while (j < v.size()) {
            if (v[i][1] <= v[j][0]) {
                i = j;
            }
            else {
                count++;
            }

            j++;
        }

        return count;
    }
};