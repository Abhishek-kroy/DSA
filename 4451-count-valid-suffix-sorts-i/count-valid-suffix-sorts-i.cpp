class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        vector<bool> pref(n + 1, true), valid(n, true);

        // Prefix matching
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] && (nums[i - 1] == target[i - 1]);
        }

        // Target suffix must be non-increasing
        for (int i = n - 2; i >= 0; i--) {
            valid[i] = valid[i + 1] && (target[i] >= target[i + 1]);
        }

        multiset<int> m1, m2;
        int ans = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Add nums[i] to m1
            auto it = m2.find(nums[i]);
            if (it != m2.end()) {
                m2.erase(it);
            } else {
                m1.insert(nums[i]);
            }

            // Add target[i] to m2
            it = m1.find(target[i]);
            if (it != m1.end()) {
                m1.erase(it);
            } else {
                m2.insert(target[i]);
            }

            if (pref[i] && valid[i] && m1.empty() && m2.empty()) {
                ans++;
            }
        }

        return ans;
    }
};