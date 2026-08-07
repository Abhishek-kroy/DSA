class Solution {
public:
    int getans(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,int mask,vector<vector<int>>& dp){
        if(dp[i][mask]!=-1)return dp[i][mask];
        int ans=0;
        for(int j=0;j<(int)mentors.size();j++){        
            if(!(mask&(1<<j))){
                int score=0;
                for(int k=0;k<(int)mentors[0].size();k++){
                    score+=(students[i][k]==mentors[j][k]);
                }

                ans=max(ans,score+getans(students,mentors,i+1,mask|(1<<j),dp));
            }
        }

        return dp[i][mask]=ans;      
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        vector<vector<int>> dp((int)students.size()+1,vector<int>((1<<(int)mentors.size())+1,-1));
        return getans(students,mentors,0,0,dp);
    }
};