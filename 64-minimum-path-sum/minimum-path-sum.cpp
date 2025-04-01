class Solution {
    unordered_map<int,int> dp;
    private:
    int getans(vector<vector<int>> &grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();

        if(i>=n || j>=m){
            return INT_MAX;
        }

        if(i==n-1 && j==m-1){
            return grid[i][j];
        }

        if(dp.find(i*m+j)!=dp.end()){
            return dp[i*m+j];
        }

        long long w1=1LL*grid[i][j]+1LL*getans(grid,i+1,j);
        long long w2=1LL*grid[i][j]+1LL*getans(grid,i,j+1);

        return dp[i*m+j]=min(w1,w2);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        return getans(grid,0,0);
    }
};