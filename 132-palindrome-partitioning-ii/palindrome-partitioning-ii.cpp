class Solution {
public:
    vector<int> dp;

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int getans(string &s, int l) {
        if (l == s.size()) return 0;

        if (dp[l] != -1) return dp[l];

        int result = INT_MAX;

        for (int i = l; i < s.size(); i++) {
            if (isPalindrome(s, l, i)) {
                result = min(result, 1 + getans(s, i + 1));
            }
        }

        return dp[l] = result;
    }

    int minCut(string s) {
        dp.assign(s.size(), -1);
        return getans(s, 0) - 1;
    }
};