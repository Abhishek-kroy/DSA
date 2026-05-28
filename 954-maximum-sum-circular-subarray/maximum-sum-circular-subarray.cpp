class Solution {
public:
    int get(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum);

            if (sum <= 0) {
                sum = 0;
            }
        }

        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int ans1 = get(nums);

        if(ans1<0){
            return ans1; 
        }

        long long total = 0;

        for (int i = 0; i < n; i++) {    
            total += nums[i];
            nums[i] = -1 * nums[i];
        }

        int ans2 = get(nums);    

        return max(ans1, (int)total + ans2);
    }
};    