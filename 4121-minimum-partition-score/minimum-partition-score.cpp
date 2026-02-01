class Solution {
public:
    long long INF = 4e15;
    vector<vector<long long>> dp;

    unsigned long long getval(long long s){
        return 1ULL * s * (s + 1) / 2;
    }

    long long getans(vector<int>& nums, int i, int j, int k, vector<long long>& prefix){
        int n = nums.size();

        if(i >= n){
            if(k == 0) return 0;
            return INF;
        }

        if(k == 0) return INF;

        if(dp[i][k] != -1) return dp[i][k];

        long long ans = INF;

        for(int ind = i; ind <= j; ind++){
            if((j - ind + 1) < (k - 1)) break;

            long long sumarr = (i == 0 ? prefix[ind] : prefix[ind] - prefix[i - 1]);
            unsigned long long value = getval(sumarr);

            if(value > ans) continue;

            long long rem = getans(nums, ind + 1, j, k - 1, prefix);

            if(value + rem > ans) continue;

            ans = min(ans, (long long)value + rem);
        }

        return dp[i][k] = ans;
    }

    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }

        dp.assign(n + 1, vector<long long>(k + 1, -1));

        return getans(nums, 0, n - 1, k, prefix);
    }
}; 