#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static map<pair<int,pair<int,int>>, int> dp;
    const int MOD = 1e9 + 7;

    long long ipow(int base, int exp) {
        long long result = 1;
        while (exp--) {
            result *= base;
        }
        return result;
    }

    int getans(int n, int x, int num) {
        if (n == 0) return 1;
        long long p = ipow(num, x);
        if (n < 0 || p > n) return 0;

        if (dp.find({n,{num,x}}) != dp.end())
            return dp[{n,{num,x}}];

        int w1 = getans(n - p, x, num + 1);
        int w2 = getans(n, x, num + 1);

        return dp[{n,{num,x}}] = (w1 + w2) % MOD;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; i <= 300; i++) {
            for (int y = 1; y <= 5; y++) {
                getans(i, y, 1);
            }
        }
        return dp[{n,{1,x}}];
    }
};

map<pair<int,pair<int,int>>, int> Solution::dp;