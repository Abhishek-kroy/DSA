class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        if(grid[n-1][m-1] || grid[0][0]){
            return -1;
        }

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int cnt=1;
        vector<int> x_dir={-1,-1,0,1,1,1,0,-1};
        vector<int> y_dir={0,-1,-1,-1,0,1,1,1};
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [x,y]=q.front();
                q.pop();

                if(x==grid.size()-1 && y==grid[0].size()-1){
                    return cnt;
                }

                for(int k=0;k<8;k++){
                    int nx=x+x_dir[k];
                    int ny=y+y_dir[k];

                    if(nx==grid.size()-1 && ny==grid[0].size()-1){
                        return cnt+1;
                    }

                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()){
                        if(!grid[nx][ny]){
                            grid[nx][ny]=1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
            cnt++;
        }

        return -1;
    }
};