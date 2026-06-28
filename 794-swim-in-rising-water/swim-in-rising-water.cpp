class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({grid[0][0],0});

        vector<vector<int>> vis(n,vector<int> (n,+0));

        // vis[0][0]=grid[0][0];          

        while(!pq.empty()){
            auto [t,cor]=pq.top();
            pq.pop();

            int x=cor/n;
            int y=cor%n;

            if(x==n-1 && y==n-1){
                return t; 
            }

            vector<int> dx={-1,0,1,0};
            vector<int> dy={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny]=1;           
                    pq.push({max(grid[nx][ny],t),nx*n+ny});
                }
            }
        }

        return -1;          
    }
};