class Solution {
public:
    int getans(vector<int>& nums,int i,int prev_i,vector<vector<int>>& dp){
        int n=nums.size();
        if(i>=n)    return 0;

        if(dp[i][prev_i+1]!=-1){
            return dp[i][prev_i+1];
        }

        long long way1=0,way2=0;
        // take
        if(prev_i==-1 || nums[prev_i]<nums[i]){
            way1=1+getans(nums,i+1,i,dp);
        }
        // ṇot take

        way2=0+getans(nums,i+1,prev_i,dp);

        return dp[i][prev_i+1]=max(way1,way2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return getans(nums,0,-1,dp);
    }
};