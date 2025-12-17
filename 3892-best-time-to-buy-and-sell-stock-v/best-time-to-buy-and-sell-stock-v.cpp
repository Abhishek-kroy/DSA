class Solution {
public:
    int n;
    vector<vector<vector<long long>>> dp;

    long long getans(vector<int>& prices, int i, int k, int state) {
        if (i == n) {
            if (state != 0) return -1e18;
            return 0;
        }

        if (k == 0) {
            // if (state != 0) return -1e18;
            return 0;
        }

        long long &res = dp[i][k][state];
        if (res != LLONG_MIN) return res;

        // option 1: skip
        res = getans(prices, i + 1, k, state);

        if (state == 0) {
            // open long
            res = max(res, -prices[i] + getans(prices, i + 1, k, 1));
            // open short
            res = max(res, +prices[i] + getans(prices, i + 1, k, 2));
        }
        else if (state == 1) {
            // close long
            res = max(res, +prices[i] + getans(prices, i + 1, k - 1, 0));
        }
        else {
            // close short
            res = max(res, -prices[i] + getans(prices, i + 1, k - 1, 0));
        }

        return res;
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.assign(n,
            vector<vector<long long>>(k + 1,
                vector<long long>(3, LLONG_MIN)));

        return getans(prices, 0, k, 0);
    }
};