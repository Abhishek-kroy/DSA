#include <algorithm> // for lower_bound

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<int> dp(n + 1, 0); // dp[i] = max substrings starting from index i
        vector<vector<int>> adj(26);
        
        for (int i = 0; i < n; i++) {
            adj[word[i] - 'a'].push_back(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            int target = i + 3;
            auto it = lower_bound(adj[ch].begin(), adj[ch].end(), target);
            int cnt = 0;

            if (it != adj[ch].end()) {
                int j = *it;
                cnt = 1 + dp[j + 1];
            }

            dp[i] = max(cnt, dp[i + 1]);
        }

        return dp[0];
    }
};