class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pow;
        int bit = 1;
        int t = n;

        while (t) {
            if (t & 1) pow.push_back(bit);
            bit <<= 1;
            t >>= 1;
        }

        vector<int> ans;
        for (auto q : queries) {
            int product = 1;
            for (int i = q[0]; i <= q[1]; i++) {
                product = (product * 1LL* pow[i]) % MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }
};