class Solution {
public:
    long long dp[15][15][2];
    const int MOD = 1e9+7;

    pair<long long,long long> getans(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();    

        if(i==n-1 && j==m-1){
            return {grid[i][j],grid[i][j]};
        }


        if(dp[i][j][1] != -1e18){
            return {dp[i][j][0],dp[i][j][1]};
        }

        long long mn=1e18, mx=-1e18;

        if(i==n-1){
            auto p=getans(grid,i,j+1);
            mn=min({mn,1LL*grid[i][j]*p.first,1LL*grid[i][j]*p.second});
            mx=max({mx,1LL*grid[i][j]*p.first,1LL*grid[i][j]*p.second});
        }
        else if(j==m-1){
            auto p=getans(grid,i+1,j);
            mn=min({mn,1LL*grid[i][j]*p.first,1LL*grid[i][j]*p.second});
            mx=max({mx,1LL*grid[i][j]*p.first,1LL*grid[i][j]*p.second});
        }
        else{
            auto p1=getans(grid,i+1,j);
            auto p2=getans(grid,i,j+1);

            mn=min({mn,
                1LL*grid[i][j]*p1.first,
                1LL*grid[i][j]*p1.second,
                1LL*grid[i][j]*p2.first,
                1LL*grid[i][j]*p2.second
            });

            mx=max({mx,
                1LL*grid[i][j]*p1.first,
                1LL*grid[i][j]*p1.second,
                1LL*grid[i][j]*p2.first,
                1LL*grid[i][j]*p2.second
            });
        }

        return {dp[i][j][0]=mn, dp[i][j][1]=mx};
    }

    int maxProductPath(vector<vector<int>>& grid) {    
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){
                dp[i][j][0]=1e18;   
                dp[i][j][1]=-1e18;    
            }
        }

        auto p=getans(grid,0,0);

        long long ans=p.second;

        if(ans<0) return -1;

        return ans%MOD;
    }
};