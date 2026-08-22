class Solution {
public:
    vector<int> dp;
    int getans(vector<int>& cost,int i){
        int n=cost.size();

        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        return dp[i]=cost[i]+min(getans(cost,i+1),getans(cost,i+2));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        if(n==1){
            return cost[0];
        }

        dp.resize(n,-1);        
        return min(getans(cost,0),getans(cost,1));
    }
};