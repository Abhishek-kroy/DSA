class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size(); 

        // vector<pair<int,int>> ans; 
        unordered_set<int> row;
        unordered_set<int> col; 


        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    // pair<int,int> p;
                    // p.first=i;
                    // p.second=j;
                    // ans.push_back(p);

                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        // for(auto i:ans){
        //     for(int k=0;k<matrix.size();k++){
        //         matrix[k][i.second]=0;
        //     }
        //     for(int k=0;k<matrix[0].size();k++){
        //         matrix[i.first][k]=0;
        //     }
        // }

        for(auto r:row){
            for(int i=0;i<m;i++){
                matrix[r][i]=0;    
            }
        }

        for(auto c:col){
            for(int i=0;i<n;i++){
                matrix[i][c]=0;    
            }
        }
    }
};