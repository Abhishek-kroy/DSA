class Solution {
public:
    unordered_map<int,int> dp;
    int getans(int i,int n){
        if(i==n){
            return 1;
        }

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }

        int w1=0,w2=0;
        
        if(i+1<=n)
        w1=getans(i+1,n);
        if(i+2<=n)
        w2=getans(i+2,n);

        return dp[i]=w1+w2;
    }

    int climbStairs(int n) {
        return getans(0,n);
    }
};