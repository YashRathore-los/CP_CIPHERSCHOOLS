int lengthOfLongestSubstring(string s)
{
    int i = 0;
    int j = 0;

    int ans = 0;

    unordered_map<char, int> ump;

    while (i < s.size())
    {
        if (ump.find(s[i]) == ump.end())
        {
            ump[s[i]]++;
            ans = max(ans, i - j + 1);

            i++;
        }
        else
        {
            ump[s[j]]--;

            if (ump[s[j]] == 0)
                ump.erase(s[j]);

            j++;

        }
    }

    return ans;
}