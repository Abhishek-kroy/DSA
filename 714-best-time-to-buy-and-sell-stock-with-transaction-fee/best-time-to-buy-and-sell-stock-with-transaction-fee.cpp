#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int getans(vector<int>& prices, int fee, int i, bool holding) {
        if (i >= prices.size()) {
            return holding ? -1e5 : 0;
        }

        if (dp[i][holding] != -1) {
            return dp[i][holding];
        }

        int w1 = 0, w2 = 0;

        if (!holding) {
            // Try to buy
            w1 = getans(prices, fee, i + 1, true) - prices[i];
            // Skip
            w2 = getans(prices, fee, i + 1, false);
        } else {
            // Try to sell
            w1 = getans(prices, fee, i + 1, false) + prices[i] - fee;
            // Skip
            w2 = getans(prices, fee, i + 1, true);
        }

        return dp[i][holding] = max(w1, w2);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return getans(prices, fee, 0, false);  // Start with no stock held
    }
};