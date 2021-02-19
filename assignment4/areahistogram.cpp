class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int>left(h.size());
        stack<pair<int, int>>s;
        for (int i = 0; i < h.size(); i++) {
            if (s.empty()) {
                left[i] = -1;
                s.push({h[i], i});
            }
            else {
                if (s.top().first < h[i]) {
                    left[i] = s.top().second;
                    s.push({h[i], i});
                }
                else {
                    while (!(s.empty() || s.top().first < h[i])) {
                        s.pop();
                    }
                    if (s.empty()) {
                        left[i] = -1;
                        s.push({h[i], i});
                    }
                    else {
                        left[i] = s.top().second;
                        s.push({h[i], i});
                    }
                }
            }
        }
        vector<int>right(h.size());
        stack<pair<int, int>>s1;
        int k = 0;
        for (int i = h.size() - 1; i >= 0; i--) {
            if (s1.empty()) {
                right[k] = h.size();
                s1.push({h[i], i});
            }
            else {
                if (s1.top().first < h[i]) {
                    right[k] = s1.top().second;
                    s1.push({h[i], i});
                }
                else {
                    while (!(s1.empty() || s1.top().first < h[i])) {
                        s1.pop();
                    }
                    if (s1.empty()) {
                        right[k] = h.size();
                        s1.push({h[i], i});
                    }
                    else {
                        right[k] = s1.top().second;
                        s1.push({h[i], i});
                    }
                }
            }
            k++;
        }
        reverse(right.begin(), right.end());
        int ans = 0;
        for (int i = 0; i < h.size(); i++) {
            int temp = (right[i] - left[i] - 1) * h[i];
            if (temp > ans) {
                ans = temp;
            }
        }
        return ans;

    }
};