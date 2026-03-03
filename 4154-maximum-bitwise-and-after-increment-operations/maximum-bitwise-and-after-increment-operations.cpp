class Solution {
public:
    // long long costl(long long v, long long mid, long long k) {
    //     long long cnt = 0;
    //     while ((v & mid) != mid) {
    //         v++;
    //         cnt++;
    //         if (cnt > k) return LLONG_MAX;
    //     }
    //     return cnt;
    // }

    long long costl(long long v, long long mid, long long k) {
        long long target = v;

        for (int bit = 30; bit >= 0; bit--) {
            if (mid & (1LL << bit)) {
                if (!(target & (1LL << bit))) {
                    long long nv = ((target >> bit) + 1) << bit;
                    target += (nv - target);
                }
            }
        }

        long long cost = target - v;

        if (cost > k) {
            return LLONG_MAX;
        }

        return cost;
    }    

    bool can(vector<int>& nums, int k, int m, long long mid) {
        int n = nums.size();
        vector<long long> cost(n);

        for (int i = 0; i < n; i++) {
            int v = nums[i];
            cost[i] = costl(v, mid, k);
        }

        sort(cost.begin(), cost.end());

        long long sum = 0;

        for (int i = 0; i < m; i++) {
            if (cost[i] > k)
                return false;
            sum += cost[i];
            if (sum > k)
                return false;
        }

        return true;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int best = 0;
        long long limit = k;

        for (int bit = 30; bit >= 0; bit--) {
            int candidate = best | (1 << bit);
            if (can(nums, k, m, candidate)) {
                best = candidate;
            }
        }
        return best;
    }
};

//  n log m log n