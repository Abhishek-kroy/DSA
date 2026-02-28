class Solution {
public:
    int getans(string s,int tight,int prev,int i,vector<vector<vector<int>>>& dp){
        int n=s.size();
        if(i>=n){
            return 1;
        }

        if(dp[i][tight][prev]!=-1){
            return dp[i][tight][prev];
        }

        int w1=0;

        int limit=(tight ? s[i]-'0':1);

        for(int j=0;j<=limit;j++){      
            int ntight=tight&&(j==limit);
            if(prev && j==1){
                continue;
            }
            w1+=getans(s,ntight,j==1 ? 1:0,i+1,dp)  ;   

        }

        dp[i][tight][prev]=w1;


        return dp[i][tight][prev]    ;  

    }

    int findIntegers(int n) {
        string s="";
        int val=n;
        while(val){
            int b=val&1;                
            s=to_string(b)+s;
            val>>=1;
        }

        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>> (2,vector<int> (2,-1)));        



        int ans=getans(s,1,0,0,dp);

        return ans; 
    }
};