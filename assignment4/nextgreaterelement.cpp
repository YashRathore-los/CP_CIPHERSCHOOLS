class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        if (n == 0) {
            return ans;
        }
        vector<int>right(n);
        stack<int>s1;
        int k = 0;
        for (int i = (n - 1); i >= 0; i--) {
            if (s1.empty()) {
                right[k] = -1;
                s1.push(nums[i]);
            }
            else {
                if (s1.top() > nums[i]) {
                    right[k] = s1.top();
                    s1.push(nums[i]);
                }
                else {
                    while (!(s1.empty() || s1.top() > nums[i])) {
                        s1.pop();
                    }
                    if (s1.empty()) {
                        right[k] = -1;
                        s1.push(nums[i]);
                    }
                    else {
                        right[k] = s1.top();
                        s1.push(nums[i]);
                    }
                }
            }
            k++;
        }
        int l = 0;
        for (int i = (n - 1); i >= 0; i--) {
            if (s1.empty()) {
                right[l] = -1;
                s1.push(nums[i]);
            }
            else {
                if (s1.top() > nums[i]) {
                    right[l] = s1.top();
                    s1.push(nums[i]);
                }
                else {
                    while (!(s1.empty() || s1.top() > nums[i])) {
                        s1.pop();
                    }
                    if (s1.empty()) {
                        right[l] = -1;
                        s1.push(nums[i]);
                    }
                    else {
                        right[l] = s1.top();
                        s1.push(nums[i]);
                    }
                }
            }
            l++;
        }
        reverse(right.begin(), right.end());

        return right;

    }
};