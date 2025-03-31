class Solution {
public:
    // unordered_map<int,int> dp;
    // int getans(int i,int n){
    //     if(i==n){
    //         return 1;
    //     }

    //     // if(dp.find(i)!=dp.end()){
    //         // return dp[i];
    //     // }

    //     int w1=0,w2=0;
        
    //     if(i+1<=n)
    //     w1=getans(i+1,n);
    //     if(i+2<=n)
    //     w2=getans(i+2,n);

    //     // return dp[i]=w1+w2;
    // }

    int climbStairs(int n) {
        // 0 1 2
        // 0 1 0
        vector<int> dp(n + 1, 0);
        dp[n]=1;

    for (int i = n - 1; i >= 0; i--) {
        if ((i + 1) <= n) {
            dp[i] = dp[i + 1];
        }
        if ((i + 2) <= n) {
            dp[i] += (dp[i + 2]);
        }
    }

    return dp[0];
        // return getans(0,n);
    }
};