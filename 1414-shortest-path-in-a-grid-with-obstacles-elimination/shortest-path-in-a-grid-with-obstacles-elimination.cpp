class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        queue<vector<int>> q;

        if(grid[0][0]){
            k--;

            if(k<0){
                return -1; 
            }
        }    

        q.push({0,0,k}); 

        vector<vector<vector<int>>> vis(n,vector<vector<int>> (m,vector<int> (k+1,0)));
        vis[0][0][k]=1; 

        vector<int> dx={-1,0,1,0};        

        vector<int> dy={0,1,0,-1};          



        int l=0; 

        while(!q.empty()){
            int sz=q.size();


            while(sz--){
                auto v=q.front();
                q.pop();

                int x=v[0];
                int y=v[1];

                if(x==n-1 && y==m-1){
                    return l;        
                }                                

                int remk=v[2];

                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];

                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(grid[nx][ny]==1 && remk-1>=0 &&   !vis[nx][ny][remk-1]){
                            vis[nx][ny][remk-1]=1;
                            q.push({nx,ny,remk-1});
                        }
                        if(grid[nx][ny]==0 && !vis[nx][ny][remk]){
                            vis[nx][ny][remk]=1;
                            q.push({nx,ny,remk});        
                        }
                    }
                }


            }                                                
            l++;         
        }

        return -1; 
    }
};