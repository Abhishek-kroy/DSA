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
        // int val=getans(coins,coins.size()-1,amount,dp);
        // if(val>10000){
        //     return -1;
        // }

        // return val;

        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0){
                dp[0][amt]=amt/coins[0];
            }
            else{
                dp[0][amt]=1e9;
            }
        }

        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<=amount;amt++){
                int w1=INT_MAX;
                if(coins[i]<=amt){
                    w1=1+dp[i][amt-coins[i]];
                }
                int w2=dp[i-1][amt];

                dp[i][amt]=min(w1,w2);
            }
        }

        int val=dp[coins.size()-1][amount];
        if(val>10000){
            return -1;
        }

        return val;

    }
};