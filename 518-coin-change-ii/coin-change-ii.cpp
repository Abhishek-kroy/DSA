class Solution {
public:
    int getans(int amount,vector<int>& coins,int i,vector<vector<int>> &dp){
        if(amount<0){
            return 0;
        }

        if(i==0){
            if(amount%coins[0]==0){
                return 1;;
            }

            return 0;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int w1=getans(amount-coins[i],coins,i,dp);
        int w2=getans(amount,coins,i-1,dp);
        return dp[i][amount]=w1+w2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        return getans(amount,coins,coins.size()-1,dp);
    }
};