class Solution {
public:
    unordered_map<long long,unordered_map<long long,unordered_map<long long,long long>>> dp;
    long long getans(int n, int start, vector<vector<int>>& requests,int t,int mask){
        int sz=requests.size();

        if(mask==(1<<sz)-1){
            return 0;
        }

        if(dp.find(mask)!=dp.end() && dp[mask].find(start)!=dp[mask].end() && dp[mask][start].find(t)!=dp[mask][start].end()){
            return dp[mask][start][t];
        }

        long long w1=LLONG_MAX;     

        for(int i=0;i<sz;i++){
            if(!(mask&(1<<i))){
                long long nstart=requests[i][1];
                long long nt=max(1LL*requests[i][0],1LL*t+1LL*abs(nstart-start));
                long long l=min(1LL*start,nstart);
                long long r=max(1LL*start,nstart);
                long long nmask=mask|(1<<i);
                for(int j=0;j<sz;j++){
                    long long f=requests[j][1];
                    long long a=requests[j][0];

                    if(f>=l && f<=r && a<=1LL*t+1LL*abs(f-start)){
                        nmask|=(1<<j);                                                
                    }
                }

                w1=min(w1,1LL*(nt-t)+1LL*getans(n,nstart,requests,nt,nmask));
            }          
        }

        return dp[mask][start][t]=w1;
    }
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        return getans(n,start,requests,0,0);
    }
};