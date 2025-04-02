class Solution {
        map<pair<int,int>,int> dp;
    int getans(vector<vector<int>>& triangle,int level,int i){
        if(level>triangle.size()){
            return 0;
        }

        if(dp.find({level,i})!=dp.end()){
            return dp[{level,i}];
        }

        // take i
        int w1=triangle[level-1][i]+getans(triangle,level+1,i);
        // take i+1
        int w2=triangle[level-1][i+1]+getans(triangle,level+1,i+1);

        return dp[{level,i}]=min(w1,w2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return triangle[0][0]+getans(triangle,2,0);
    }
};