int longestPalindromeSubseq(string s) {
	const auto n = s.size();
	vector<int> old_cache(n, 0);
	vector<int> cache(n, 0);

	old_cache[n - 1] = 1;

	for (size_t i = n - 1; i-- != 0;) {
		cache[i] = 1;
		for (size_t j = i + 1; j != n; ++j) {
			if (s[i] == s[j]) {
				cache[j] = old_cache[j - 1] + 2;
			} else {
				cache[j] = max(cache[j - 1], old_cache[j]);
			}
		}
		swap(cache, old_cache);
	}

	return old_cache[n - 1];
}