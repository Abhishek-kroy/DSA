#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT() {}
    BIT(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    long long sum(int idx) const {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }
};

struct Query {
    int L, R, idx, block;
};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (k <= 1) return 0; // any window of size 0/1 has 0 inversions

        // ----- coordinate compression -----
        vector<int> comp = nums;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = int(lower_bound(comp.begin(), comp.end(), nums[i]) - comp.begin()) + 1; // [1..M]
        }
        int M = (int)comp.size();

        // ----- build queries: all windows of length k -----
        int q = n - k + 1;
        vector<Query> queries;
        queries.reserve(q);
        int blockSize = max(1, (int)sqrt(n));

        for (int i = 0; i + k - 1 < n; ++i) {
            Query qu;
            qu.L = i;
            qu.R = i + k - 1;
            qu.idx = i;                    // store start index as id
            qu.block = i / blockSize;
            queries.push_back(qu);
        }

        sort(queries.begin(), queries.end(),
             [&](const Query& x, const Query& y) {
                 if (x.block != y.block) return x.block < y.block;
                 // Hilbert-like ordering optimization (optional)
                 if (x.block & 1) return x.R > y.R;
                 return x.R < y.R;
             });

        // ----- Mo's algorithm with BIT over values -----
        BIT bit(M);
        long long currInv = 0;
        int currL = 0, currR = -1;
        long long currLen = 0;

        auto addRight = [&](int pos) {
            int v = a[pos];
            long long greater = currLen - bit.sum(v); // elements with value > v
            currInv += greater;
            bit.add(v, 1);
            ++currLen;
        };

        auto removeRight = [&](int pos) {
            int v = a[pos];
            long long greater = currLen - bit.sum(v); // as when added
            currInv -= greater;
            bit.add(v, -1);
            --currLen;
        };

        auto addLeft = [&](int pos) {
            int v = a[pos];
            long long less = bit.sum(v - 1); // elements with value < v
            currInv += less;
            bit.add(v, 1);
            ++currLen;
        };

        auto removeLeft = [&](int pos) {
            int v = a[pos];
            long long less = bit.sum(v - 1); // same as when added
            currInv -= less;
            bit.add(v, -1);
            --currLen;
        };

        vector<long long> ans(q);

        for (const auto& qu : queries) {
            int L = qu.L;
            int R = qu.R;

            while (currL > L) addLeft(--currL);
            while (currR < R) addRight(++currR);
            while (currL < L) removeLeft(currL++);
            while (currR > R) removeRight(currR--);

            ans[qu.idx] = currInv;
        }

        // ----- get minimum inversion count over all windows -----
        long long best = ans[0];
        for (int i = 1; i < q; ++i) {
            best = min(best, ans[i]); 
        }
        return best;
    }
}; 