class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> vis(n,vector<int> (n,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vis[i][j]=0; 
                    q.push({i,j});                                                  
                }
            }
        }

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};                         

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]>1+vis[x][y]){
                    vis[nx][ny]=1+vis[x][y];
                    q.push({nx,ny});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({vis[0][0],{0,0}});

        vector<vector<int>> dis(n,vector<int> (n,-1));
        dis[0][0]=vis[0][0];

        int ans=0; 

        while(!pq.empty()){

            auto [safe, pos] = pq.top();
            auto [x,y] = pos;
            pq.pop(); 

            if(x==n-1 && y==n-1){
                return dis[x][y]; 
            }

            if(safe < dis[x][y])
                continue;        

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && dis[nx][ny]<min(vis[nx][ny],dis[x][y])){
                    dis[nx][ny]=min(vis[nx][ny],dis[x][y]);
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }                

        return ans; 
    }
};