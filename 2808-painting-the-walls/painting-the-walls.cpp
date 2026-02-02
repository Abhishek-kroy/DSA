class Solution {
public:
    long long getans(vector<int>& cost, vector<int>& time,int i,int sel,vector<vector<long long>>& dp){
        int n=cost.size();

        if(sel>=n){
            return 0; 
        }

        if(i>=n){
            if(sel<n){      
                return 1e9 ;   
            }
            return 0;
        }   

        if(dp[i][sel]!=-1){
            return dp[i][sel]; 
        }


        // take
        long long w1=cost[i]+getans(cost,time,i+1,sel+time[i]+1,dp);    


        long long w2=0+getans(cost,time,i+1,sel,dp);     

        dp[i][sel]=min(w1,w2); 
        return dp[i][sel]; 
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        long long total=0;
        int n=cost.size();    
        for(auto t:time){
            total+=t;
        }
        vector<vector<long long>> dp(n,vector<long long> (n+1,-1));       
        return getans(cost,time,0,0,dp);  
    }
};