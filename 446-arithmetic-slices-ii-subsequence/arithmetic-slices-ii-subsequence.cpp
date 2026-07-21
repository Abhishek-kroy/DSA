class Solution {
public:
    // int getans(vector<int>& nums,int i,int d){
    //     if(i==nums.size()){
    //         return 0;
    //     }

    // }

    int ncr(int n, int r) {
        // return n! / r!
        int v1 = 1;
        for (int i = 0; i < r; i++) {
            v1 *= (n - i);
        }

        int v2 = 1;
        for (int i = 1; i <= r; i++) {
            v2 *= i;
        }

        return v1 / v2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, int>> f(n);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i -1; j >=0; j--) {
                long long d = 1LL*nums[j] - 1LL*nums[i];

                ans += f[j][d];
                f[i][d] += f[j][d]+1;       
            }         
        }

        return ans;
    }
};