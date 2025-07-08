class Solution {
public:
    int bs(vector<vector<int>>& events, int val) {
        int l = 0, r = events.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] < val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    int getans(vector<vector<int>>& events, vector<vector<int>>& dp, int k, int i) {
        if (k == 0 || i >= events.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        int next = bs(events, events[i][1] + 1);
        int pick = events[i][2] + getans(events, dp, k - 1, next);
        int skip = getans(events, dp, k, i + 1);

        return dp[i][k] = max(pick, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return getans(events, dp, k, 0);
    }
};