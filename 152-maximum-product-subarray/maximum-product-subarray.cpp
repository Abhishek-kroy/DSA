class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int maxProd = INT_MIN;
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            // If prefix becomes 0, reset it to 1
            prefix = (prefix == 0) ? 1 : prefix;
            suffix = (suffix == 0) ? 1 : suffix;

            prefix *= nums[i];         // Forward traversal
            suffix *= nums[n - 1 - i]; // Backward traversal

            maxProd = max(maxProd, max(prefix, suffix));
        }

        return maxProd;
    }
};