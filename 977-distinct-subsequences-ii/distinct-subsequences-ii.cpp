class Solution {
public:
    int distinctSubseqII(string s) {
        int mod=1e9+7;        
        int n=s.size();

        vector<int> last(26,-1);

        vector<long long> dp(n);

        dp[0]=1;
        last[s[0]-'a']=0;           

        for(int i=1;i<n;i++){
            dp[i]=((dp[i-1]+dp[i-1])%mod+1)%mod;
            int ind=last[s[i]-'a'];
            if(ind>0)
                dp[i]=((dp[i]-(dp[ind-1]+1)%mod)+mod)%mod;  
            else if(ind==0){
                dp[i]=((dp[i]-1)%mod+mod)%mod;
            }  

            last[s[i]-'a']=i;
        }

        return dp[n-1];        
    }
};