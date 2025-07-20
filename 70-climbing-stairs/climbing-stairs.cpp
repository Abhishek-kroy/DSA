class Solution {
public:
    int getans(int n,vector<int>& dp){
        if(n==0){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        long long w1=0,w2=0;

        w1=getans(n-1,dp);

        if(n>1){
            w2=getans(n-2,dp);
        }

        return dp[n]=w1+w2;
    }
    int climbStairs(int n) {

        vector<int> dp(n+1,-1);
        return getans(n,dp);
    }
};