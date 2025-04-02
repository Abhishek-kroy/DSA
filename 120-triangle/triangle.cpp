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
        vector<int> dp=triangle.back();

        for(int level=triangle.size()-2;level>=0;level--){
            vector<int> temp(triangle[level].size()+1);
            for(int j=0;j<=level;j++){
                temp[j]=triangle[level][j]+min(dp[j],dp[j+1]);
            }
            dp=temp;
        }

        return dp[0];
        // return triangle[0][0]+getans(triangle,2,0);
    }
};