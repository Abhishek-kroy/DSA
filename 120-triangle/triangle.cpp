class Solution {
    //     map<pair<int,int>,int> dp;
    // int getans(vector<vector<int>>& triangle,int level,int i){
    //     if(level>triangle.size()){
    //         return 0;
    //     }

    //     if(dp.find({level,i})!=dp.end()){
    //         return dp[{level,i}];
    //     }

    //     // take i
    //     int w1=triangle[level-1][i]+getans(triangle,level+1,i);
    //     // take i+1
    //     int w2=triangle[level-1][i+1]+getans(triangle,level+1,i+1);

    //     return dp[{level,i}]=min(w1,w2);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int> (triangle.back().size(),-1));
        for(int j=0;j<triangle.back().size();j++){
            dp[triangle.size()-1][j]=triangle[triangle.size()-1][j];
        }

        for(int level=triangle.size()-2;level>=0;level--){
            for(int j=0;j<=level;j++){
                dp[level][j]=triangle[level][j]+min(dp[level+1][j],dp[level+1][j+1]);
            }
        }
        // 2
        // 3 4
        // 6 5 7
        // 4 1 8 3

        return dp[0][0];
        // return triangle[0][0]+getans(triangle,2,0);
    }
};