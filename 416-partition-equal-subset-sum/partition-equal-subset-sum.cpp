class Solution {
    private:
        bool getans(vector<int>& nums,int sum,vector<vector<int>> &dp,int i){
            if(sum==0){
                return true;
            }
            if(sum<0 || i>=nums.size()){
                return false;
            }

            if(dp[i][sum]!=-1){
                return dp[i][sum];
            }

            if(getans(nums,sum-nums[i],dp,i+1))
                return dp[i][sum]=true;
            
            return dp[i][sum]=getans(nums,sum,dp,i+1);
        }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto val:nums){
            sum+=val;
        }

        if(sum%2){
            return false;
        }

        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        sum/=2;

        return getans(nums,sum,dp,0);
    }
};