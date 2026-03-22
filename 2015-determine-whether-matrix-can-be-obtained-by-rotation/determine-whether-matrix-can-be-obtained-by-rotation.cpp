class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> t(n,vector<int>(m));

        int k=m-1;

        for(int i=0;i<n;i++){
            int l=0;
            for(int j=0;j<m;j++){    
                t[l][k]=mat[i][j];
                l++;                                                                                   
            }
            k--;
        }

        mat=t;    
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }

        for(int i=0;i<3;i++){
            rotate(mat);
            if(mat==target){
                return true;    
            }
        }

        return false; 
    }
};