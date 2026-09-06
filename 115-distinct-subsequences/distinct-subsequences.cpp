class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    int getans(string& s,string& t,int i,int j){
        if(j<0){
            return 1;
        }

        if(i<0){
            return 0;
        }

        if(dp.find(i)!=dp.end() && dp[i].find(j)!=dp[i].end()){
            return dp[i][j];
        }

        int w=0;
        if(s[i]==t[j]){
            w+=getans(s,t,i-1,j-1);
        }

        w+=getans(s,t,i-1,j);

        return dp[i][j]=w;                        
    }

    int numDistinct(string s, string t) {
        return getans(s,t,(int)s.size()-1,(int)t.size()-1);
    }
};