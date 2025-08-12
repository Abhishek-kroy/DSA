class Solution {
public:
    map<pair<int,int>,int> dp;
    const int MOD = 1e9 + 7 ;
    int getans(int n,int x,int num){
        if(n==0){
            return 1;
        }
        if(n<0 || pow(num,x)>n){
            return 0;
        }

        if(dp.find({n,num})!=dp.end())  return dp[{n,num}];

        int w1=getans(n-pow(num,x),x,num+1);
        int w2=getans(n,x,num+1);

        return dp[{n,num}]=(w1+w2)%MOD;
    }
    int numberOfWays(int n, int x) {
        return getans(n,x,1);
    }
};