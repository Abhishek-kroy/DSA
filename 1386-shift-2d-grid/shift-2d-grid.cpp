class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();


        k=k%(m*n);    

        while(k--){
            int ele=grid[n-1][m-1];         
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    if(i==0 && j==0){
                        grid[i][j]=ele;
                        continue;
                    }
                    int key1=i*m+j;
                    int key2=key1-1;
                    int nx=key2/m;
                    int ny=key2%m;

                    grid[i][j]=grid[nx][ny];
                }
            }
        }


        return grid; 
    }
};