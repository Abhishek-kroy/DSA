class Solution {
    unordered_map<int,int> dp;
    private:
        int getans(int m,int n,int i,int j){
            if(i==n-1 || j==m-1){
                return 1;
            }

            if(dp.find(i*m+j)!=dp.end()){
                return dp[i*m+j];
            }

            int w1=0;
            w1+=getans(m,n,i+1,j);
            w1+=getans(m,n,i,j+1);

            return dp[i*m+j]=w1;                      
        }
public:
    
    int uniquePaths(int m, int n) {
        return getans(m,n,0,0);
    }
};