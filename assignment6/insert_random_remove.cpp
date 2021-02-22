class RandomizedSet {
	unordered_map<int, int>st;
	vector<int>num;

public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (!st.count(val)) {
			num.emplace_back(val);
			st[val] = num.size() - 1;
			return true;
		}
		return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (st.count(val)) {
			auto currentIdx = st[val]; // swapping the last index and current index to remove the element in constant time
			int lastIndex = num.size() - 1;
			st[num[lastIndex]] = currentIdx;
			swap(num[lastIndex], num[currentIdx]);
			st.erase(val);
			num.pop_back();
			return true;
		}
		return false;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int  n = num.size();
		int randomIdx = rand() % n;
		return num[randomIdx];
	}
};