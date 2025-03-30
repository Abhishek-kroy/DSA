class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshcnt=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    freshcnt++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
                else{
                    continue;
                }
            }
        }

        if(freshcnt==0){
            return 0;
        }
        
        int min=0;
        while(!q.empty()){
            min++;
            int size=q.size();
            while(size--){
                auto [i,j]=q.front();
                q.pop();
                vector<int> x={-1,0,1,0};
                vector<int> y={0,-1,0,1};

                for(int k=0;k<4;k++){
                    int ni=i+x[k];
                    int nj=j+y[k];

                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        if(grid[ni][nj]==1){
                            freshcnt--;
                            q.push({ni,nj});
                            grid[ni][nj]=2;
                        }
                    }
                }
            }
        }

        return freshcnt==0 ? min-1 : -1;

    }
};