class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int i=0;
        int j=0;
        int m=mat.size();
        int n=mat[0].size();
        while(ans.size()<m*n){
            // upward 

            while(i>=0 && j<n && ans.size()<m*n){
                if(i<m && j>=0){
                    ans.push_back(mat[i][j]);
                    if(i==m-1 && j==n-1)    break;
                }
                i--;
                j++;
            }

            i++;

            while(i<m && j>=0 && ans.size()<m*n){
                if(i>=0 && j<n){
                    ans.push_back(mat[i][j]);
                    if(i==m-1 && j==n-1)    break;
                }

                i++;
                j--;
            }

            j++;
            // downward 
        }

        return ans;
    }
};