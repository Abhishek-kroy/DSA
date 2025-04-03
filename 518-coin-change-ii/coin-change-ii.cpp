class Solution {
public:
    int getans(int amount,vector<int>& coins,int i,vector<vector<int>> &dp){
        // if(amount<0){
        //     return 0;
        // }

        if(i==0){
            if(amount%coins[0]==0){
                return 1;;
            }

            return 0;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int w1=0;
        if(coins[i]<=amount)
        w1=getans(amount-coins[i],coins,i,dp);
        int w2=getans(amount,coins,i-1,dp);
        return dp[i][amount]=w1+w2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<long>> dp(coins.size(),vector<long> (amount+1,0));
        // return getans(amount,coins,coins.size()-1,dp);
        for(int amt=0;amt<=amount;amt++){
            if(amt%coins[0]==0){
                dp[0][amt]=1;
            }
            else{
                dp[0][amt]=0;
            }
        }


        for(int i=1;i<coins.size();i++){
            for(int amt=0;amt<=amount;amt++){
                int w1=0;
                if(coins[i]<=amt)
                w1=dp[i][amt-coins[i]];
                int w2=dp[i-1][amt];
                dp[i][amt]=1LL*w1+1LL*w2;
            }
        }

        return dp[coins.size()-1][amount];

    }
};