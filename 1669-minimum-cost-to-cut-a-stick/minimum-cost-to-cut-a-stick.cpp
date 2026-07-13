class Solution {
public:
    int dp[101][101];        
    int getans(int l,int r,vector<int>& cuts,int i,int j){

        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        long long ans=INT_MAX;

        for(int k=i;k<=j;k++){    

            long long left = getans(l,cuts[k],cuts,i,k-1);
            long long right = getans(cuts[k],r,cuts,k+1,j);

            long long cost = (r-l) + left + right;            

            ans = min(ans,cost);
        }          

        return dp[i][j]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return getans(0,n,cuts,0,(int)cuts.size()-1);
    }
};            