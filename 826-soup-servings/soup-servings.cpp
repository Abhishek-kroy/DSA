class Solution {
public:
    unordered_map<long long,double> dp;
    double getans(int a,int b){
        if(a==0 && b!=0){
            return 1.0;
        }

        if(a==0 && b==0){
            return 0.5;
        }

        if(a!=0 && b==0)    return 0.0;

        if(dp.find(a*1e9+b)!=dp.end())  return dp[a*1e9+b];

        double w1=getans(max(0,a-100),max(0,b-0));
        double w2=getans(max(0,a-75),max(0,b-25));
        double w3=getans(max(0,a-50),max(0,b-50));
        double w4=getans(max(0,a-25),max(0,b-75));

        return dp[a*1e9+b]=0.25*(w1+w2+w3+w4);
    }
    double soupServings(int n) {
        if(n>=4801) return 1.0;
        return getans(n,n);
    }
};