class Solution {
    unordered_map<int,long> dp;
    private:
        long getans(vector<vector<int>> &questions,int i){
            int n=questions.size();
            if(i>=n){
                return 0;
            }

            if(dp.find(i)!=dp.end()){
                return dp[i];
            }

            // take
            long w1=1LL*questions[i][0]+1LL*getans(questions,i+questions[i][1]+1);
            // not take
            long w2=1LL*getans(questions,i+1);

            return dp[i]=max(w1,w2);


        }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return getans(questions,0);
    }
};