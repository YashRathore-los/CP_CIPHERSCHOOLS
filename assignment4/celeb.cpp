class Solution {
public:
    int celebrity(vector<vector<int> >& M, int n) {
        // code here
        stack<int>s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        while (s.size() >= 2) {
            int A = s.top();
            s.pop();
            int B = s.top();
            s.pop();
            if (M[A][B] == 1) {
                s.push(B);
            }
            else {
                s.push(A);
            }
        }
        int celb = s.top();
        for (int i = 0; i < n; i++) {
            if (M[celb][i] == 1) {
                return -1;
            }
            if (M[i][celb] == 0 and i != celb) {
                return -1;
            }
        }
        return celb;
    }
};