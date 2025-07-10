#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int i = 0, j = 0, n = nums.size();
        long long sum = 0;
        unordered_map<int, int> freq;

        while (j < n) {
            freq[nums[j]]++;
            sum += nums[j];

            while (freq[nums[j]] > 1) {
                freq[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k) {
                ans = max(ans, sum);
                freq[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};