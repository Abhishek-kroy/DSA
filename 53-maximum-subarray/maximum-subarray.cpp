class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=INT_MIN;
        while(j<n){
            sum+=nums[j];
            ans=max(ans,sum);
            while(sum<0){
                sum-=nums[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};