class Solution {
public:

    int getans(vector<pair<int,int>> &cnt,int z,int o,int i,int m,int n,vector<vector<vector<int>>>& dp){
        if(i>=cnt.size())   return 0;
        if(dp[i][z][o]!=-1){
            return dp[i][z][o];
        }
        int w1=0,w2=0;
        // take
        if(z+cnt[i].first<=m && o+cnt[i].second<=n){
            w1=1+getans(cnt,z+cnt[i].first,o+cnt[i].second,i+1,m,n,dp); 
        }

        // not take 
        w2=getans(cnt,z,o,i+1,m,n,dp);

        return dp[i][z][o]=max(w1,w2); 
    }
    int findMaxForm(vector<string>& strs, int m, int n) { 
        vector<vector<vector<int>>> dp(strs.size(),vector<vector<int>> (m+1,vector<int> (n+1,-1)));        
        vector<pair<int,int>> cnt(strs.size(),{0,0});
        int i=0;
        for(auto str:strs){
            int zero=0;
            int one=0;
            for(auto c:str){
                if(c=='0')  zero++;
                else    one++;
            }
            cnt[i]={zero,one}; 
            i++; 
        }

        return getans(cnt,0,0,0,m,n,dp);
    }
};