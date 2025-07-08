class Solution {
public:
    
    unordered_map<int,int> bsdp;

    int bs(vector<vector<int>>& events, int val) {
        if(bsdp.find(val)!=bsdp.end()) return bsdp[val];
        int l = 0, r = events.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] < val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return bsdp[val]=l;
    }

    unordered_map<int, unordered_map<int, int>> dp;

    int getans(vector<vector<int>>& events, int k, int i) {
        if (k == 0 || i >= events.size()) return 0;

        if (dp[i].count(k)) return dp[i][k];

        int next = bs(events, events[i][1] + 1);
        int pick = events[i][2] + getans(events, k - 1, next);

        int skip = getans(events, k, i + 1);

        return dp[i][k] = max(pick, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        return getans(events, k, 0);
    }
};