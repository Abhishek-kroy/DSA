class Solution {
public:
    unordered_map<long long, int> dp;

    bool perfectSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    int getans(vector<int>& nums, int mask, int prevIndex) {
        int n = nums.size();
        if (mask == (1 << n) - 1) return 1;

        long long key = ((long long)mask << 12) | (prevIndex + 1);
        if (dp.find(key) != dp.end()) return dp[key];

        int ways = 0;
        unordered_set<int> usedHere; 

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0 && usedHere.count(nums[i]) == 0) {
                if (prevIndex == -1 || perfectSquare(nums[prevIndex] + nums[i])) {
                    usedHere.insert(nums[i]);
                    ways += getans(nums, mask | (1 << i), i);
                }
            }
        }

        return dp[key] = ways;
    }

    int numSquarefulPerms(vector<int>& nums) {
        return getans(nums, 0, -1);
    }
};