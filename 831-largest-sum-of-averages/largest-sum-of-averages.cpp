#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, double> dp;

    double getans(vector<int>& nums, int i, int k) {
        int n = nums.size();
        if (k == 1) {
            double sum = 0;
            for (int j = i; j < n; j++) sum += nums[j];
            return sum / (n - i);
        }

        string key = to_string(i) + "," + to_string(k);
        if (dp.count(key)) return dp[key];

        double sum = 0, maxAvg = 0;
        for (int j = i; j <= n - k; ++j) {
            sum += nums[j];
            double currAvg = sum / (j - i + 1);
            maxAvg = max(maxAvg, currAvg + getans(nums, j + 1, k - 1));
        }

        return dp[key] = maxAvg;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        return getans(nums, 0, k);
    }
};