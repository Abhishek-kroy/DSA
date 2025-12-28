class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // [4,3,2,-1]
        // [3,2,1,-1]
        // [1,1,-1,-2]
        // [-1,-1,-2,-3]
        int n=grid.size();
        int m=grid[0].size();

        int i=n-1;
        int j=0;

        int cnt=0;

        while(i>=0 && j<m){
            if(grid[i][j]<0){
                cnt+=(m-j);        
                i--;
            }
            else{
                int ind=upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin();     
                j=ind;
                // cout<<i<<" "<<j<<endl;  
            }
        }

        return cnt;
    }
};