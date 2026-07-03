class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> h(n,vector<int> (m,0));

        h[0][0]= grid[0][0] ? health-1 : health; 

        // for(int j=1;j<m;j++){
        //     h[0][j]=max(h[0][j],h[0][j-1]-grid[0][j]); 
        // }

        // for(int i=1;i<n;i++){
        //     h[i][0]=max(h[i][0],h[i-1][0]-grid[i][0]); 
        // }

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};          

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){

        //         for(int k=0;k<4;k++){

        //             int ni=i+dx[k];
        //             int nj=j+dy[k];

        //             if(ni>=0 && ni<n && nj>=0 && nj<m){
        //                 h[ni][nj]=max(h[i][j],h[i-1][j]-grid[i][j]);                
        //             }

        //         }             
        //     }
        // }

        queue<pair<int,int>> q; 
        q.push({0,0});

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

              for(int k=0;k<4;k++){

                    int ni=x+dx[k];
                    int nj=y+dy[k];

                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        if(h[ni][nj]<h[x][y]-grid[ni][nj]){
                            h[ni][nj]=h[x][y]-grid[ni][nj];
                            q.push({ni,nj});      
                        }
                    }

                }                   
        }

        return h[n-1][m-1]>0;          
    }
};