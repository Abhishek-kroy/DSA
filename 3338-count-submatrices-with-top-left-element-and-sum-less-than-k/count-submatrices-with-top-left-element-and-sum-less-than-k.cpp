class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> pre(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    pre[i][j]=grid[i][j];
                }
                else{
                    pre[i][j]=pre[i][j-1]+grid[i][j];
                }
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    if(pre[i][j]<=k){
                        ans++;                                                
                    }
                }
                else{
                    int sum=pre[i][j]+pre[i-1][j];
                    if(sum<=k){
                        ans++;    
                    }
                    pre[i][j]=sum;
                }   
            }
        }

        return ans;        
    }
};