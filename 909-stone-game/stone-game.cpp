#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<pair<int,int>,int> dp;

    int getans(vector<int>& piles, int i, int j, vector<int>& suffix) {
        if (j - i + 1 <= 2) {
            int res = max(piles[i], piles[j]);
            return res;
        }

        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        int w1 = piles[i] + getans(piles, i + 2, j, suffix);

        int w2 = piles[i] + getans(piles, i + 1, j - 1, suffix);

        int w3 = piles[j] + getans(piles, i, j - 2, suffix);

        int w4 = piles[j] + getans(piles, i + 1, j - 1, suffix);

        int total = suffix[i]-suffix[j+1];
        if (w1 > total - w1) {
            return dp[{i, j}] = w1;
        }
        if (w2 > total - w2) {
            return dp[{i, j}] = w2;
        }
        if (w3 > total - w3) {
            return dp[{i, j}] = w3;
        }
        if (w4 > total - w4) {
            return dp[{i, j}] = w4; 
        }
        return dp[{i, j}] = w4;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> suffix(n+1, piles[n - 1]);
        suffix[n]=0;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        int w1=getans(piles, 0, n - 1, suffix);
        return w1>suffix[0]-w1;

        return true;
    }
};