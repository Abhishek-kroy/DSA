#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<long long>>> dp;
    int K;

    long long dfs(const vector<vector<int>>& adj, int node,
                  const vector<int>& nums, int k, int d,
                  vector<int>& visited, bool inverted) {
        int distState = min(d, K);

        long long& res = dp[node][distState][inverted];
        if (res != LLONG_MIN) return res;

        visited[node] = 1;

        long long w1 = inverted ? -nums[node] : nums[node];
        for (int nei : adj[node])
            if (!visited[nei])
                w1 += dfs(adj, nei, nums, k, d + 1, visited, inverted);

        long long ans = w1;

        if (d >= k) {
            long long w2 = inverted ? nums[node] : -nums[node];
            for (int nei : adj[node])
                if (!visited[nei])
                    w2 += dfs(adj, nei, nums, k, 1, visited, !inverted);

            ans = max(ans, w2);
        }

        visited[node] = 0;
        res = ans;
        return res;
    }

    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        K = k;
        dp.assign(n, vector<vector<long long>>(k + 1, vector<long long>(2, LLONG_MIN)));
        vector<int> visited(n, 0);

        return dfs(adj, 0, nums, k, k, visited, false);
    }
};