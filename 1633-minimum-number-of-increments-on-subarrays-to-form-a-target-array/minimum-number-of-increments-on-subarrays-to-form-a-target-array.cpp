#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int n = target.size();
        int val = target[0];
        int prevval = 0;

        for (int i = 1; i < n - 1; i++) {
            if (target[i] <= target[i-1] && target[i] <= target[i+1]) {
                ans += val - prevval;
                val = target[i+1];
                prevval = target[i];
                i++;
            } else {
                val = max(val, target[i]);
            }
        }

        val = max(val, target[n-1]);
        ans += val - prevval;
        return ans;
    }
}; 