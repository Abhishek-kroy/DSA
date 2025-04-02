class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp=matrix.back();
        vector<int> temp(matrix[0].size());

        for(int level=matrix.size()-2;level>=0;level--){
            for(int j=0;j<matrix[0].size();j++){
                temp[j]=matrix[level][j]+min({dp[j],j+1<matrix.size() ? dp[j+1]:INT_MAX,j>0 ? dp[j-1]: INT_MAX});
            }
            dp=temp;
        }

        int ans=INT_MAX;

        for(auto v:dp){
            ans=min(ans,v);
        }

        return ans;
    }
};