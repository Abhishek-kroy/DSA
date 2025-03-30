class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        
        int col=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            vector<int> x_dir={-1,0,1,0};
            vector<int> y_dir={0,-1,0,1};
            for(int k=0;k<4;k++){
                int nx=x+x_dir[k];
                int ny=y+y_dir[k];
                if(nx>=0 and nx<image.size() and ny>=0 and ny<image[0].size()){
                    if(image[nx][ny]==col){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return image;

    }
};