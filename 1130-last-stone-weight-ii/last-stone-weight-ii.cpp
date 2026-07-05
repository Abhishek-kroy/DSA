class Solution {
public:
    int getans(vector<int>& stones,int i,long long sum,long long t,vector<vector<int>>& dp){
        int n=stones.size();           

        if(i>=n){
            return abs(2*sum-t);                            
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        return dp[i][sum]= min(getans(stones,i+1,sum+stones[i],t,dp),getans(stones,i+1,sum,t,dp));        
    }

    int lastStoneWeightII(vector<int>& stones) {

        int n=stones.size();          

        long long t=0;           

        for(auto s:stones){
            t+=s;
        }        

        vector<vector<int>> dp(n,vector<int> (100*n+1,-1));

        // t=t/2;

        return getans(stones,0,0,t,dp);                              
    }
};