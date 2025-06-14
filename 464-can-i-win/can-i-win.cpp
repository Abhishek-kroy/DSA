class Solution {
public:
    unordered_map<string, bool> dp;

    bool getans(int maxChoosableInteger, int desiredTotal, string &s) {
        if (dp.count(s)) return dp[s];

        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (s[i - 1] == '0') {
                s[i - 1] = '1';

                if (desiredTotal - i <= 0 || !getans(maxChoosableInteger, desiredTotal - i, s)) {
                    s[i - 1] = '0';
                    return dp[s] = true;
                }

                s[i - 1] = '0';
            }
        }

        return dp[s] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        string s(maxChoosableInteger, '0');
        return getans(maxChoosableInteger, desiredTotal, s);
    }
};