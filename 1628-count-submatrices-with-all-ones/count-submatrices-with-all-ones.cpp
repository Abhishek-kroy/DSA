class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> h(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    h[j]=1+h[j];
                }
                else{
                    h[j]=0;
                }
                int w=h[j];
                for(int k=j;k>=0;k--){
                    w=min(w,h[k]);
                    ans+=w;
                }
            }
        }

        return ans;
    }
};