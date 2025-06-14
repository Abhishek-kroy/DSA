class Solution {
public:
    unordered_map<int, bool> dp;

    bool getans(int maxChoosableInteger, int desiredTotal, int used) {
        if (dp.count(used)) return dp[used];

        for (int i = 0; i < maxChoosableInteger; i++) {
            if (!(used & (1 << i))) { // number (i+1) not used
                if (desiredTotal <= i + 1 || 
                    !getans(maxChoosableInteger, desiredTotal - (i + 1), used | (1 << i))) {
                    return dp[used] = true; // current player wins
                }
            }
        }

        return dp[used] = false; // no winning move
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;

        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;

        return getans(maxChoosableInteger, desiredTotal, 0); // 0 → no numbers used yet
    }
};