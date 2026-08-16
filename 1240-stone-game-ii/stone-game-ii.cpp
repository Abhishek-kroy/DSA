class Solution {
public:
    vector<int> suf;
        unordered_map<int,unordered_map<int,int>> dp;
    int getans(vector<int>& piles,int m,int i){
        int n=piles.size();

        if(i>=n){
            return 0;
        }

        if(dp.find(i)!=dp.end() && dp[i].find(m)!=dp[i].end()){
            return dp[i][m];
        }

        int ans=0;
        for(int x=1;x<=2*m && i+x-1<n;x++){
            int w1=getans(piles,max(m,x),i+x);
            ans=max(ans,suf[i]-w1);                                      
        }

        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();

        suf.resize(n,0);
        suf[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]+=piles[i]+suf[i+1];
        }

        return getans(piles,1,0);
    }
};