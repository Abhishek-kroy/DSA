class Solution {
public:
    int getans(vector<int> &nums, int target, int val, int i, vector<vector<int>> &dp, int offset) {
        if (i >= nums.size()) {
            return (val == target) ? 1 : 0;
        }

        if (dp[i][val + offset] != -1) {
            return dp[i][val + offset];
        }

        int w1 = getans(nums, target, val + nums[i], i + 1, dp, offset);
        int w2 = getans(nums, target, val - nums[i], i + 1, dp, offset);

        return dp[i][val + offset] = w1 + w2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (target > sum || target < -sum) return 0;
        
        int offset = sum;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return getans(nums, target, 0, 0, dp, offset);
    }
};