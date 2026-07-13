class Solution {
public:
    int mod = 1e9+7;

    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();

        long long tcost = 0;
        long long cnt = 0;

        int rem = k;

        for (int i = 0; i < n; i++) {

            if (nums[i] > rem) {

                int t = (nums[i] - rem + k - 1) / k;

                rem += t * k;
                tcost = (tcost + (1LL * (t % mod) * (cnt % mod)) % mod + (1LL * (t % mod) * ((t + 1) % mod) / 2) % mod) % mod;            

                cnt += t;
            }

            rem -= nums[i];
        }

        return tcost;
    }
};           