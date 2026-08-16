class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    int getans(vector<int>& piles,int i,int j){
        int n=piles.size();

        if(i>j){
            return 0;          
        }        

        if(dp.find(i)!=dp.end() && dp[i].find(j)!=dp[i].end()){
            return dp[i][j];
        }

        int w1=piles[i]-getans(piles,i+1,j);        
        int w2=piles[j]-getans(piles,i,j-1);

        return dp[i][j]=max(w1,w2);        
    }

    bool stoneGame(vector<int>& piles) {
        int ans=getans(piles,0,(int)piles.size()-1);
        return ans;
    }
};