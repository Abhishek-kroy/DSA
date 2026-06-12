class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int i=0, j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
            int c=max_element(mat[mid].begin(),mat[mid].end())-mat[mid].begin();
            if(mat[mid+1][c]>mat[mid][c]) i=mid+1;
            else j=mid;
        }
        int c=max_element(mat[i].begin(),mat[i].end())-mat[i].begin();
        return {i,c};
    }
}; 