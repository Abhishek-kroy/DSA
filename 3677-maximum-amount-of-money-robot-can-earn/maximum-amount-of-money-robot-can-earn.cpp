class Solution {
public:
    vector<vector<vector<int>>> dp;

    int getans(vector<vector<int>>& coins,int i,int j,int k){
        int n=coins.size();                                        
        int m=coins[0].size();                                        

        if(i>=n || j>=m){
            return -1e8;
        }

        if(dp[i][j][k]!=-1e8) return dp[i][j][k];

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

        w1=max({w1,coins[i][j]+getans(coins,i+1,j,k),coins[i][j]+getans(coins,i,j+1,k)});
        if(k>0 && coins[i][j]<0){
            w1=max({w1,0+getans(coins,i+1,j,k-1),0+getans(coins,i,j+1,k-1)});   
        }

        return dp[i][j][k]=w1;   
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,-1e8)));
        return getans(coins,0,0,2);
    }
};   