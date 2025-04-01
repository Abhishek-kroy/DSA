class Solution {
    // unordered_map<int,int> dp;
    // private:
    //     int getans(int m,int n,int i,int j,vector<vector<int>>& obstacleGrid){
    //         if(i>=n || j>=m || obstacleGrid[i][j]==1){
    //             return 0;
    //         }

    //         if(i==n-1 && j==m-1){
    //             return 1;
    //         }

    //         if(dp.find(i*m+j)!=dp.end()){
    //             return dp[i*m+j];
    //         }

    //         int w1=0;
    //         w1+=getans(m,n,i+1,j,obstacleGrid);
    //         w1+=getans(m,n,i,j+1,obstacleGrid);

    //         return dp[i*m+j]=w1;                      
    //     }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        // return getans(m,n,0,0,obstacleGrid);

        vector<vector<long long>> dp(n,vector<long long>(m,-1));

        dp[n-1][m-1]=!obstacleGrid[n-1][m-1];
        for(int j=m-2;j>=0;j--){
            if(obstacleGrid[n-1][j]==1){
                dp[n-1][j]=0;
            }
            else{
                dp[n-1][j]=dp[n-1][j+1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(obstacleGrid[i][m-1]==1){
                dp[i][m-1]=0;
            }
            else{
                dp[i][m-1]=dp[i+1][m-1];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j]=0;
                if(obstacleGrid[i][j]!=1){
                    dp[i][j]+=dp[i][j+1];
                    dp[i][j]+=dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }
};