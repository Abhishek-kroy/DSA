class Solution {
public:
    int getans(string& str1,string& str2, int i,int j, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];      
        }

        if(str1[i]==str2[j]){
            dp[i][j]=1+getans(str1,str2,i-1,j-1,dp);
        }

        return dp[i][j]=max({dp[i][j],getans(str1,str2,i-1,j,dp),getans(str1,str2,i,j-1,dp)}); 
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        int l=getans(str1,str2,n-1,m-1,dp);        

        string ans="";

        int i=n-1;
        int j=m-1;

        while(i>=0 && j>=0){
            if(str1[i]==str2[j]){
                ans=str1[i]+ans;
                i--;
                j--;
            }
            else{
                int up=(i>0) ? dp[i-1][j]:0;
                int lf=(j>0) ? dp[i][j-1]:0;

                if(up>=lf){
                    i--;
                }
                else{
                    j--;
                }
            }
        }

        string res="";

        i=0;
        j=0;
        int k=0;

        while(i<n && j<m && k<l){      
            while(str1[i]!=ans[k]){
                res+=str1[i];
                i++;
            }

            while(str2[j]!=ans[k]){
                res+=str2[j];
                j++;
            }

            res+=ans[k];        

            i++;
            j++;
            k++;
        }

        while(i<n){
            res+=str1[i];        
            i++;
        }

        while(j<m){
            res+=str2[j];
            j++;        
        }

        return res;        
    }
};