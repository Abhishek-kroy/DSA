class Solution {
public:
    int getans(string& s1,int i,string& s2,int j,vector<vector<int>>& dp){    
        if(i<0 && j<0)  return 0;
        if(i<0){
            return 97+(s2[j]-'a')+getans(s1,i,s2,j-1,dp);
        }
        if(j<0){
            return 97+(s1[i]-'a')+getans(s1,i-1,s2,j,dp);  
        }

        if(dp[i][j]!=-1)    return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j]=getans(s1,i-1,s2,j-1,dp);           
        }

        return dp[i][j]=min(97+(s1[i]-'a')+getans(s1,i-1,s2,j,dp),97+(s2[j]-'a')+getans(s1,i,s2,j-1,dp));                            
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();    

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getans(s1,n-1,s2,m-1,dp);      
    }
};