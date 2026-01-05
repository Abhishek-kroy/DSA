class Solution {
public:
    unordered_map<int,int> dp;

    int MOD = 1e9+7 ; 
    int getans(int n, vector<int> &prefix){
        if(n <= 1){
            return 1;
        }

        if(dp.find(n)!=dp.end())    return dp[n];

        int a = getans(n-1, prefix)%MOD;
        int b = getans(n-2, prefix)%MOD;

        int w1 = (a + b)%MOD;

        if(n >= 3){
            w1 = (w1 +(2 * prefix[n-3]%MOD))%MOD;             
        }

        prefix[n] = (prefix[n-1] + w1)%MOD;  

        return dp[n]=w1;
    }

    int numTilings(int n) {
        vector<int> prefix(n+1, 0);
        prefix[0] = 1;
        prefix[1] = 2;

        return getans(n, prefix);
    }
}; 