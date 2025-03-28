class Solution {
public:
    unordered_map<int,int> dp;
    int getans(string s,int i=0){
        if(s[i]=='0') return 0;
        if(i>=s.size()){
            return 1;
        }

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }

        int w1=0;

        if(i==s.size()-1){
            w1+=getans(s,i+1);
        }
        else if(s[i]=='1'){
            w1+=getans(s,i+1);
            w1+=getans(s,i+2);
        }
        else if(s[i]=='2'){
            w1+=getans(s,i+1);
            if(s[i+1]>='0' and s[i+1]<='6')
                w1+=getans(s,i+2);
        }
        else{
            w1+=getans(s,i+1);
        }

        return dp[i]=w1;
    }
    int numDecodings(string s) {
        return getans(s,0)   ;
    }
};