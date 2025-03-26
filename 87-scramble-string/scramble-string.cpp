#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;

    bool getans(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + "|" + s2;
        if (dp.count(key)) return dp[key];

        int n = s1.size();
        
        string sorted_s1 = s1, sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());

        if (sorted_s1 != sorted_s2) return dp[key] = false;
        
        for (int i = 1; i < n; i++) {
            if (getans(s1.substr(0, i), s2.substr(0, i)) &&
                getans(s1.substr(i), s2.substr(i))) {
                return dp[key] = true;
            }
            if (getans(s1.substr(0, i), s2.substr(n - i)) &&
                getans(s1.substr(i), s2.substr(0, n - i))) {
                return dp[key] = true;
            }
        }
        
        return dp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        dp.clear();
        return getans(s1, s2);
    }
};