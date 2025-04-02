auto init = [](){cin.tie(0)->sync_with_stdio(0);return 0;}();
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    unordered_map<long long, long long> parent, height;

public:
    void addNode(long long u) {
        if (parent.find(u) == parent.end()) {
            parent[u] = u;
            height[u] = 1;
        }
    }

    long long findPar(long long u) {
        if (parent[u] == u) return u;
        return parent[u] = findPar(parent[u]); // Path Compression
    }

    void unionSetByHeight(long long u, long long v) {
        addNode(u);
        addNode(v);
        long long ulp_u = findPar(u), ulp_v = findPar(v);
        if (ulp_u == ulp_v) return;

        if (height[ulp_u] >= height[ulp_v]) {
            parent[ulp_v] = ulp_u;
            height[ulp_u] += height[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            height[ulp_v] += height[ulp_u];
        }
    }
};

// Helper function to compute LCM safely
#include <numeric>
long long lcm(long long a, long long b) {
    long long g = gcd(a, b);
    return (1LL * a / g) * b;
}

class Solution {
public:
    int countComponents(vector<int>& nums, long long threshold) {
        sort(nums.begin(), nums.end());
        DisjointSet ds;
        
        // Add all numbers to DSU
        for (long long val : nums) ds.addNode(val);

       for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <=threshold; j+=nums[i]) {
                ds.unionSetByHeight(nums[i], j);
            }
        }

        // Count unique components
        unordered_set<long long> uniqueComponents;
        for (long long v : nums) {
            uniqueComponents.insert(ds.findPar(v));
        }

        return uniqueComponents.size();
    }
};