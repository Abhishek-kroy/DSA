class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size(); 

        // vector<pair<int,int>> ans; 
        // unordered_set<int> row;
        // unordered_set<int> col; 

        bool rzero=false;
        bool czero=false; 


        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    // pair<int,int> p;
                    // p.first=i;
                    // p.second=j;
                    // ans.push_back(p);

                    // row.insert(i);
                    // col.insert(j);

                    if(i==0){
                        rzero=true;
                    }

                    if(j==0){
                        czero=true; 
                    }

                    matrix[i][0]=0;
                    matrix[0][j]=0;  
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

        for(int j=1;j<n;j++){
            if(matrix[j][0]!=0){
                continue; 
            }

            for(int i=0;i<m;i++){    
                matrix[j][i]=0;    
            }
        }

        for(int j=1;j<m;j++){      
            if(matrix[0][j]!=0){
                continue; 
            }

            for(int i=0;i<n;i++){
                matrix[i][j]=0;    
            }
        }

        if(matrix[0][0]==0){

            if(rzero){
                for(int j=0;j<m;j++){
                    matrix[0][j]=0;
                }
            }

            if(czero){
                for(int j=0;j<n;j++){
                    matrix[j][0]=0;
                }
            }
        }  
    }
};