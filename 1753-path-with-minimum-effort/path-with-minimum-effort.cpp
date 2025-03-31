#define wxy pair<int, pair<int, int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int min_effort=INT_MAX;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> efforts(n,vector<int> (m,INT_MAX));
        efforts[0][0]=0;
        priority_queue<wxy,vector<wxy>,greater<wxy>> pq;

        pq.push({0,{0,0}});

        vector<int> x_dir={-1,0,1,0};
        vector<int> y_dir={0,-1,0,1};

        while(!pq.empty()){
            auto [effort,l] = pq.top();
            auto [x,y]=l;

            pq.pop();

            for(int k=0;k<4;k++){
                int nx=x+x_dir[k];
                int ny=y+y_dir[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(max(effort,abs(heights[nx][ny]-heights[x][y]))<efforts[nx][ny]){
                        efforts[nx][ny]=max(effort,abs(heights[nx][ny]-heights[x][y]));
                        pq.push({efforts[nx][ny],{nx,ny}});
                    }
                }
            }
        }

        return efforts[n-1][m-1];

    }
};