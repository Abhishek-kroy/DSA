class Solution {
public:
    bool getans(vector<int>& nums,int i,int t,vector<vector<int>>& dp){
        int n=nums.size();

        if(t<0){
            return false;
        }

        if(i==n){
            return t==0;
        }

        if(dp[i][t]!=-1){
            return dp[i][t];
        }

        bool w1=getans(nums,i+1,t,dp);
        bool w2=getans(nums,i+1,t-nums[i],dp);          

        dp[i][t]=w1||w2; 

        return w1||w2;        

    }

    bool canPartition(vector<int>& nums) {
        int total=0;         
        for(auto c:nums){
            total+=c;
        }

        if(total%2){
            return false;
        }

        vector<vector<int>> dp(nums.size(),vector<int>(total/2+1,-1));

        bool ans=getans(nums,0,total/2,dp);   
        
        return ans;         
    }
};