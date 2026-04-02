class Solution {
public:
    int dp[500][500][3];
    int INF = -1e9;

    int getans(vector<vector<int>>& coins,int i,int j,int k){
        int n=coins.size();                                        
        int m=coins[0].size();                                        

        if(i>=n || j>=m){
            return -1e8;
        }

        if(dp[i][j][k]!=INF) return dp[i][j][k];

        if(i==n-1 && j==m-1){
            if(coins[i][j]>=0){
                return dp[i][j][k]=coins[i][j];
            }

            if(k>0){
                return dp[i][j][k]=0;
            }

            return dp[i][j][k]=coins[i][j];
        }

        int w1=-1e8;

        w1=max({w1,coins[i][j]+getans(coins,i+1,j,k),
                     coins[i][j]+getans(coins,i,j+1,k)});

        if(k>0 && coins[i][j]<0){
            w1=max({w1,
                    getans(coins,i+1,j,k-1),
                    getans(coins,i,j+1,k-1)});
        }

        return dp[i][j][k]=w1;   
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<3;k++)
                    dp[i][j][k]=INF;

        return getans(coins,0,0,2);
    }
};   