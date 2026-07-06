class Solution {
public:
    int dp[20][4001];
    int getans(vector<int>& nums,int target,int i){
        int n=nums.size();

        if(i>=n){
            return target==0;
        }

        if(dp[i][target+2000]!=-1){
            return dp[i][target+2000];
        }

        int w1=getans(nums,target+nums[i],i+1);
        int w2=getans(nums,target-nums[i],i+1);

        return dp[i][target+2000]=w1+w2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        memset(dp,-1,sizeof(dp));        
        
        int ans=getans(nums,target,0);


        return ans;          
    }
};