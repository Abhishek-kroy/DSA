class Solution {
public:
    vector<char> dp;

    bool getans(int maxChoosableInteger, int desiredTotal, int used) {
        if (dp[used] != -1) return dp[used];

        for (int i = 0; i < maxChoosableInteger; i++) {
            if (!(used & (1 << i))) {
                if (desiredTotal <= i + 1 || 
                    !getans(maxChoosableInteger, desiredTotal - (i + 1), used | (1 << i))) {
                    return dp[used] = 1;
                }
            }
        }

        return dp[used] = 0;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        dp.assign(1 << maxChoosableInteger, -1);
        return getans(maxChoosableInteger, desiredTotal, 0);
    }
};