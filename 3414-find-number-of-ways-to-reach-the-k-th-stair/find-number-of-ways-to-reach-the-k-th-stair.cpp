class Solution {
public:
    unordered_map<string,int> dp; 

    long long power(long long a,long long b){
        long long res=1;

        while(b){
            if(b&1){
                res=res*a;
            }

            a=a*a;
            b=b>>1;
        }

        return res;    
    }

    int getans(int s,int k,int could,int jump){
        if(s>k){
            if(s>k+1){
                return 0;
            }
            if(jump==0){
                return 2;
            }

            return 1; 
        }

        string ss=to_string(s)+"_"+to_string(could)+"_"+to_string(jump);

        if(dp.find(ss)!=dp.end()){
            return dp[ss];
        }

        int w1=getans(1LL*s+power(2,jump),k,true,jump+1);

        int w2=0;

        if(could && s>0){
            w2=getans(s-1,k,!could,jump);
        }

        if(s==k){
            return dp[ss]=1+w1+w2;            
        }

        return dp[ss]=w1+w2;      
    }
    int waysToReachStair(int k) {
        return getans(1,k,true,0);
    }
};