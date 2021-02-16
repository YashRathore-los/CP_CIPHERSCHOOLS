int equalPartition(int n, int arr[])
{

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + arr[i];
	}
	if (sum % 2 != 0) {
		return false;
	}
	int s = sum / 2;
	bool tt[n + 1][s + 1];
	for (int i = 0; i < s + 1; i++) {
		tt[0][i] = false;
	}
	for (int i = 0; i < n + 1; i++) {
		tt[i][0] = true;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < s + 1; j++) {
			if (arr[i - 1] <= j) {
				tt[i][j] = tt[i - 1][j - arr[i - 1]] || tt[i - 1][j];
			}
			if (arr[i - 1] > j) {
				tt[i][j] = tt[i - 1][j];
			}
		}
	}
	return tt[n][s];

}