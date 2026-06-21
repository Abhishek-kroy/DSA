class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> vis(n,vector<int> (m,INT_MAX));  

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});

        vis[0][0]=0; 


        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};         

        while(!pq.empty()){
            auto v=pq.top();

            int val=v[0];                              
            int x=v[1];      
            int y=v[2];              

            pq.pop();

            if(x==n-1 && y==m-1){
                return val;
            }            

            int v1=heights[x][y];        

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int v2=heights[nx][ny];

                    int nval=max(val,abs(v2-v1));

                    if(vis[nx][ny]>nval){
                        vis[nx][ny]=nval;
                        pq.push({nval,nx,ny});                                                      
                    }
                }
            }
        }

        return 1;        
    }
};