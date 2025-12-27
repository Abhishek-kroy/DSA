class Solution {
public:
    int getans(vector<int>& pre,int cnt,int len,int i,vector<vector<int>>& dp){ 
        int n=pre.size();
        if(i>=n){
            return 0;
        }

        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }

        if(cnt==0){
            if(i==0){
                return pre[n-1];
            }

            return pre[n-1]-pre[i-1];
        }

        // cover
        int w1=getans(pre,cnt-1,len,i+len,dp);

        // not cover
        int iswhite=(i==0 ? pre[0]: pre[i]-pre[i-1]);
        int w2=(iswhite)+getans(pre,cnt,len,i+1,dp);

        return dp[i][cnt]=min(w1,w2); 
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {

        int n=floor.size();
        vector<vector<int>> dp(n,vector<int> (numCarpets+1,-1));   
        vector<int> pre(n);
        pre[0]=floor[0]-'0';     
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(floor[i]=='1' ? 1:0);
        }
        return getans(pre,numCarpets,carpetLen,0,dp);
    }
};