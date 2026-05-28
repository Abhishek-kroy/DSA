class NumMatrix {
public:
    vector<vector<int>> presum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        presum.resize(n);
        for(int i=0;i<n;i++){
            presum[i].resize(m);
        }

        presum[0][0]=matrix[0][0];

        for(int i=1;i<m;i++){
            presum[0][i]=presum[0][i-1]+matrix[0][i];
        }

        for(int i=1;i<n;i++){
            presum[i][0]=presum[i-1][0]+matrix[i][0];
        }

        for(int i=1;i<n;i++){
            int pre=matrix[i][0];    
            for(int j=1;j<m;j++){
                presum[i][j]=presum[i-1][j]+pre+matrix[i][j];
                pre+=matrix[i][j];                                         
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2][col2]-(col1>0 ? presum[row2][col1-1]:0)-(row1>0 ? presum[row1-1][col2]:0)+(row1 >0 && col1>0  ?  presum[row1-1][col1-1]:0);    
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */