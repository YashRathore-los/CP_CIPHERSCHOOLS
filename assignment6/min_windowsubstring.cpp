bool fulfilled(unordered_map<char, int>& m) {  // O(1) as the maximum size of the map is 128
    for (const auto& item : m) {
        if (item.second > 0) return false;
    }
    return true;
}

string minWindow(string s, string t) {
    if (s.empty() || s.size() < t.size()) return "";

    unordered_map<char, int> count;
    for (char c : t) {
        count[c]++;
    }

    int start = 0, end = 0;
    int minIdx = -1, minLen = INT_MAX;

    while (end <= s.size() && start <= end) {
        if (!fulfilled(count)) { // expand to right
            if (count.find(s[end]) != count.end()) {
                count[s[end]]--;
            }
            end++;
        } else { // shrink
            if (end - start < minLen) {
                minLen = end - start;
                minIdx = start;
            }
            if (count.find(s[start]) != count.end()) {
                count[s[start]]++;
            }
            start++;
        }
    }
    return minIdx == -1 ? "" : s.substr(minIdx, minLen);
}