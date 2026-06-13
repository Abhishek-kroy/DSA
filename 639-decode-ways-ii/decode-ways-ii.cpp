class Solution {
public:
    long long mod=1e9+7;
    vector<long long> dp;

    long long getans(string& s,int i){
        int n=s.size();

        if(i>=n){
            return 1;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        if(s[i]=='0'){
            return dp[i]=0;
        }

        if(s[i]=='*'){
            long long w1=(9LL*getans(s,i+1))%mod;

            long long w2=0;

            if(i+1<n){
                if(s[i+1]=='*'){
                    w2=(15LL*getans(s,i+2))%mod;
                }
                else{
                    w2=getans(s,i+2)%mod;

                    if(s[i+1]<='6'){
                        w2=(w2+getans(s,i+2))%mod;
                    }
                }
            }

            return dp[i]=(w1+w2)%mod;
        }

        long long w1=getans(s,i+1)%mod;

        long long w2=0;

        if(s[i]=='1' && i+1<n){
            if(s[i+1]=='*'){
                w2=(9LL*getans(s,i+2))%mod;
            }
            else{
                w2=getans(s,i+2)%mod;
            }
        }

        if(s[i]=='2' && i+1<n){
            if(s[i+1]=='*'){
                w2=(6LL*getans(s,i+2))%mod;
            }
            else if(s[i+1]<='6'){
                w2=getans(s,i+2)%mod;
            }
        }

        return dp[i]=(w1+w2)%mod;
    }

    int numDecodings(string s) {
        dp.assign(s.size(),-1);
        return getans(s,0);
    }
}; 