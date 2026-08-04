class Solution {
public:
    const long long INF = -(1LL << 60);

    long long getans(vector<int>& nums,int i,vector<long long>& dp){
        int n=nums.size();          

        if(i>=n){
            return 0;
        }

        if (dp[i] != INF)
            return dp[i];            

        if(i==n-1){
            return nums[i];
        }

        long long w1=1LL*nums[i]+getans(nums,i+1,dp);

        long long w2=1LL*nums[i]-1LL*nums[i+1]+getans(nums,i+2,dp);                 

        return dp[i]=max(w1,w2);
    }
    long long maximumTotalCost(vector<int>& nums) {
        vector<long long> dp(nums.size(), INF);

        return getans(nums,0,dp);            
    }
};