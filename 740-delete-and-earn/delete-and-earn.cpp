class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> f;
        for(auto c:nums){
            f[c]++;
        }

        int ans=0; 

        vector<vector<int>> dp(10001,vector<int> (2,0));
        
        dp[0][0]=0;
        dp[0][1]=0;          

        dp[1][1]=f[1]*1; 
        dp[1][0]=0;         


        for(int i=2;i<10001;i++){  
            dp[i][1]=f[i]*i+max(dp[i-2][1],dp[i-2][0]); 

            dp[i][0]=max(dp[i-1][1],dp[i-1][0]);            

            ans=max({ans,dp[i][0],dp[i][1]});
        }

        return ans; 
    }
};