class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<long long> dp(n, 0);

        int left = -1, prev = -1;
        int val = 0;

        for (int i = 0; i < n; i++) {
            val = arr[i];

            if (val % 2 == 0) {
                dp[i] = (i > 0 ? dp[i - 1] : 0);
            } 
            else {
                dp[i] = (i - left) % MOD;

                if (prev != -1) {
                    dp[i] = (dp[i] + dp[prev]) % MOD;
                }

                prev = left;
                left = i;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + dp[i]) % MOD;
        }

        return ans;    
    }
};