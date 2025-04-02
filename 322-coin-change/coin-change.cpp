class Solution {
public:
    // map<pair<int,int>,int> dp;
    int getans(vector<int> &coins,int i,int amount,vector<vector<int>> &dp){
        if(i==0){
            if(amount%coins[i]==0)  return amount/coins[i];
            return 1e9;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int w1=INT_MAX;
        if(coins[i]<=amount){
            w1=1+getans(coins,i,amount-coins[i],dp);
        }

        int w2=getans(coins,i-1,amount,dp);

        return dp[i][amount]=min(w1,w2);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int val=getans(coins,coins.size()-1,amount,dp);
        if(val>10000){
            return -1;
        }

        return val;
    }
};