class Solution {
    unordered_map<int,int> dp;
    private:
        int getans(int m,int n,int i,int j,vector<vector<int>>& obstacleGrid){
            if(i>=n || j>=m || obstacleGrid[i][j]==1){
                return 0;
            }

            if(i==n-1 && j==m-1){
                return 1;
            }

            if(dp.find(i*m+j)!=dp.end()){
                return dp[i*m+j];
            }

            int w1=0;
            w1+=getans(m,n,i+1,j,obstacleGrid);
            w1+=getans(m,n,i,j+1,obstacleGrid);

            return dp[i*m+j]=w1;                      
        }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return getans(m,n,0,0,obstacleGrid);
    }
};