class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();

        int m=grid[0].size();

        vector<vector<int>> cnt(m,vector<int>(10,0));

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                cnt[j][grid[i][j]]++;
            }


        }

        // cout<<"worked cnt"<<endl;

        vector<vector<int>> dp(m,vector<int>(10,-1e6));

        for(int v1=0;v1<=9;v1++){
            dp[0][v1]=(n-cnt[0][v1]);
        }

        for(int j=1;j<m;j++){
            for(int v1=0;v1<=9;v1++){
                dp[j][v1]=INT_MAX;
                for(int v2=0;v2<=9;v2++){
                    if(v1==v2){
                        continue;
                    }

                    dp[j][v1]=min(dp[j][v1],(n-cnt[j][v1])+(dp[j-1][v2]));
                }
            }
        }        

        // cout<<"worked dp "<<endl;

        int ans=INT_MAX;





        for(int i=0;i<=9;i++){
            ans=min(ans,dp[m-1][i]);
        }

        return ans; 
    }
};