class Solution {
	public int jump(int[] nums) {
		int[]dp = new int[nums.length + 1];
		if
		(nums[0] == 0 || nums.length == 0)
			return 0;
		dp[0] = 0;
		for
		(int i = 1; i <= nums.length; i++) {
			dp[i] = Integer.MAX_VALUE;
			for
			(int j = 0; j < i; j++) {
				if
				(i <= j + nums[j] && dp[j] != Integer.MAX_VALUE) {
					dp[i] = Math.min(dp[i], dp[j] + 1);
					break;
				}
			}
		}
		return dp[nums.length - 1];
	}
}