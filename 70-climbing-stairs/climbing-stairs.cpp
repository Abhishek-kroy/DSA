class Solution {
public:
    int dp[46];

    int getans(int n){
        if(n<=2){
            return n;
        }      

        if(dp[n]!=-1){
            return dp[n]; 
        }

        int w1=getans(n-1)+getans(n-2);        

        dp[n]=w1;

        return w1;           
    }

    int climbStairs(int n) {
        if(n<=2){
            return n;
        }            

        memset(dp,-1,sizeof(dp));

        return getans(n);          
    }
};