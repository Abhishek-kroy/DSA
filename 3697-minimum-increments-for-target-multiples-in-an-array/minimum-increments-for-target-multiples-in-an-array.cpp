class Solution {
public:
    vector<vector<long long>> dp;
    const long long INF = 1e18;

    long long getans(vector<int>& nums, vector<int>& target, int i, int mask) {

        if (i == nums.size()) {
            int fullMask = (1 << target.size()) - 1;
            return (mask == fullMask) ? 0 : INF;
        }

        if (dp[i][mask] != -1)
            return dp[i][mask];

        long long ans = getans(nums, target, i + 1, mask);

        for (int k = 0; k < target.size(); k++) {

            if (mask & (1 << k))
                continue;

            int cost = (target[k] - nums[i] % target[k]) % target[k];
            int nval = nums[i] + cost;

            int newMask = mask;

            for (int l = 0; l < target.size(); l++) {
                if (nval % target[l] == 0)
                    newMask |= (1 << l);
            }

            ans = min(ans,
                      (long long)cost +
                      getans(nums, target, i + 1, newMask));
        }

        return dp[i][mask] = ans;
    }

    int minimumIncrements(vector<int>& nums, vector<int>& target) {

        dp.assign(nums.size(),
                  vector<long long>(1 << target.size(), -1));

        return getans(nums, target, 0, 0);
    }
};