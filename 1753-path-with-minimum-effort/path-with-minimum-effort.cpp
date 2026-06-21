class Solution {
public:
    bool check(vector<vector<int>>& heights,int v){


        int n=heights.size();
        int m=heights[0].size();



        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<int>> vis(n,vector<int> (m,0));

        while(!q.empty()){
            int x=q.front().first;                        
            int y=q.front().second;

            q.pop();

            if(x==n-1 && y==m-1){
                return true;    
            }

            int v1=heights[x][y];      

            vector<int> dx={-1,0,1,0};                        
            vector<int> dy={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int v2=heights[nx][ny];

                    if(abs(v2-v1)<=v && !vis[nx][ny]){
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }                                        
                }
            }                        
        }    

        return false; 
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0;

        int r=1e6;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(heights,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l; 
    }
};