class Solution {
public:
    const int MIN = -1e7;
    unordered_map<long long, int> memo;

    long long getKey(int idx, int k, int prod, int parity) {
        return (((long long)idx * 200001LL + (k + 100000)) * 5001LL + prod) * 2LL + parity;
    }

    int f(vector<int>& nums, int k, int limit, int idx, int prod, int cnt) {
        if (idx >= nums.size()) {
            if (k == 0 && cnt > 0 && limit >= prod) {
                return prod;
            }
            return MIN;
        }

        int parity = cnt % 2;
        long long key = getKey(idx, k, prod, parity);
        if (memo.count(key)) return memo[key];

        int take = MIN;
        if (cnt % 2 == 0) {
            take = f(nums, k - nums[idx], limit, idx + 1, min(limit + 1, prod * nums[idx]), cnt + 1);
        } else {
            take = f(nums, k + nums[idx], limit, idx + 1, min(limit + 1, prod * nums[idx]), cnt + 1);
        }

        int skip = f(nums, k, limit, idx + 1, prod, cnt);
        return memo[key] = max(take, skip);
    }

    int maxProduct(vector<int>& nums, int k, int limit) {
        memo.clear();
        int ans = f(nums, k, limit, 0, 1, 0);
        return (ans == MIN ? -1 : ans);
    }
};