class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        __uint128_t num = 0;  
        vector<int> ans;

        for (int v : nums) {
            if (v >= 128) continue;  
            if ((num & ((__uint128_t)1 << v)) == 0)
                num |= ((__uint128_t)1 << v);
            else
                ans.push_back(v);
        }

        return ans;
    }
};