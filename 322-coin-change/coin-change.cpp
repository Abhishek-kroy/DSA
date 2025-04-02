class Solution {
public:
    map<pair<int,int>,int> dp;
    int getans(vector<int> &coins,int i,int amount){
        if(i==0){
            if(amount%coins[i]==0)  return amount/coins[i];
            return 1e9;
        }

        if(dp.find({i,amount})!=dp.end()){
            return dp[{i,amount}];
        }

        int w1=INT_MAX;
        if(coins[i]<=amount){
            w1=1+getans(coins,i,amount-coins[i]);
        }

        int w2=getans(coins,i-1,amount);

        return dp[{i,amount}]=min(w1,w2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int val=getans(coins,coins.size()-1,amount);
        if(val>10000){
            return -1;
        }

        return val;
    }
};