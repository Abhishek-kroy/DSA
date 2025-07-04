class Solution {
public:
    int getans(int pos,string digit,int tight,int ones,vector<vector<vector<int>>> &dp){
        if(pos==digit.size())   return ones;
        if(dp[pos][tight][ones]!=-1){
            return dp[pos][tight][ones];
        }
        int limit = tight ? digit[pos]-'0' : 9;

        int w=0;

        for(int i=0;i<=limit;i++){
            bool newtight=tight&&(i==limit);
            w+=getans(pos+1,digit,newtight,i==1? ones+1:ones,dp);
        }

        return dp[pos][tight][ones]=w;

    }
    int countDigitOne(int n) {
        string digit=to_string(n);
        vector<vector<vector<int>>> dp(digit.size(),vector<vector<int>> (2,vector<int> (digit.size()+1,-1)));
        return getans(0,digit,1,0,dp);
    }
};