class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int col=n-1;
        int size=0;
        vector<vector<int>> ans(n,vector<int>(n));
        while(size<n*n){
            int i=0;
            int j=col;
            vector<int> t;
            while(i<n && j<n && size<n*n){
                if(i>=0 && j>=0){
                    t.push_back(grid[i][j]);
                    size++;
                }
                i++;
                j++;
            }
            i=0;
            j=col;
            if(col<=0)
                sort(t.begin(),t.end(),greater<int>());
            else
                sort(t.begin(),t.end());
            int k=0;
            while(i<n && j<n){
                if(i>=0 && j>=0){
                    ans[i][j]=t[k];
                    k++;
                }
                i++;
                j++;
            }
            col--;
        }   
        return ans;
    }
};