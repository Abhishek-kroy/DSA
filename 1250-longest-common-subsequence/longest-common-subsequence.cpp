class Solution {
public:
    int dp[1000][1000];
    int getans(string& text1,string& text2,int i,int j){
        int n=text1.size();
        int m=text2.size();

        if(i>=n || j>=m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j]; 
        }

        if(text1[i]==text2[j]){
            dp[i][j]=1+getans(text1,text2,i+1,j+1);
            return dp[i][j];
        }

        dp[i][j]=max(getans(text1,text2,i+1,j),getans(text1,text2,i,j+1));  
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return getans(text1,text2,0,0);
    }
};