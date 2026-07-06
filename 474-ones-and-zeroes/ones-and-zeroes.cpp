class Solution {
public:
    int dp[600][101][101]; 
    int getans(vector<string>& strs,vector<vector<int>>& cnt,int m,int n,int i){
        int s=strs.size();

        if(i>=s){          
            return 0;
        }


        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        // take 
        int w1=0;
        if(cnt[i][0]<=m && cnt[i][1]<=n){        
            w1=1+getans(strs,cnt,m-cnt[i][0],n-cnt[i][1],i+1);
        }

        int w2=getans(strs,cnt,m,n,i+1);

        return dp[i][m][n]=max(w1,w2);           
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        vector<vector<int>> cnt(s,vector<int> (2,0));

        for(int i=0;i<s;i++){
            int z=0;
            int o=0;
            string str=strs[i];

            for(auto v:str){
                if(v=='0'){
                    z++;
                }
                else{
                    o++;
                }
            }

            cnt[i]={z,o};
        }

        memset(dp,-1,sizeof(dp)); 

        return getans(strs,cnt,m,n,0);
    }
};