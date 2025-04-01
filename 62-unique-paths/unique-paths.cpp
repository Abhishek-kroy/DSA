class Solution {
    // unordered_map<int,int> dp;
    // private:
    //     int getans(int m,int n,int i,int j){
    //         if(i==n-1 || j==m-1){
    //             return 1;
    //         }

    //         if(dp.find(i*m+j)!=dp.end()){
    //             return dp[i*m+j];
    //         }

    //         int w1=0;
    //         w1+=getans(m,n,i+1,j);
    //         w1+=getans(m,n,i,j+1);

    //         return dp[i*m+j]=w1;                      
    //     }
public:
    
    int uniquePaths(int m, int n) {
        // return getans(m,n,0,0);

        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dp[n-1][j]=1;
        }
        for(int i=0;i<n;i++){
            dp[i][m-1]=1;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=0;
                dp[i][j]+=dp[i][j+1];
                dp[i][j]+=dp[i+1][j];
            }
        }

        return dp[0][0];
        
    }
};