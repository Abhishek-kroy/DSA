class Solution {
public:
    int dp[46];    
    int getans(int i,int n){
        if(i==n){
            return 1;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int w1=getans(i+1,n); 
        int w2=0;

        if(i+2<=n){
            w2=getans(i+2,n);
        }

        dp[i]=w1+w2; 

        return w1+w2; 
    }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));    
        return getans(0,n);
    }
};