#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> filled;
        set<int> dryDays;

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake > 0) {
                if (filled.find(lake) != filled.end()) {
                    auto it = dryDays.upper_bound(filled[lake]);
                    if (it == dryDays.end()) {
                        return {};
                    }
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                filled[lake] = i;
                ans[i] = -1;
            } else {
                dryDays.insert(i);
            }
        }
        return ans;
    }
};