class Solution {
public:
    unordered_map<int,int> dp;
    int getans(string s,int i){
        int n=s.size();
        if(i>=n){
            return 1;
        }

        if(dp.find(i)!=dp.end())    return dp[i];
        
        if(s[i]=='0'){
            return 0;
        }

        int w1=getans(s,i+1);
        int w2=0;
        if(s[i]=='1' && (i+1)<n){
            w2=getans(s,i+2);
        }
        if(s[i]=='2' && (i+1)<n && s[i+1]<='6'){
            w2=getans(s,i+2);
        }

        return dp[i]=w1+w2;
    }
    int numDecodings(string s) {
        return getans(s,0);
    }
};