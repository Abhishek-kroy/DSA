class Solution { 
public: 
    vector<int> dp;

    int getans(vector<int>& stones,int i,int pre){ 
        int n=stones.size(); 
 
        if(i>=n){ 
            return 0; 
        } 
 
        if(i==n-1){ 
            return pre;            
        }

        if(dp[i] != INT_MIN){
            return dp[i];
        }
     
        int ans=max(
            pre-getans(stones,i+1,pre+stones[i+1]),
            getans(stones,i+1,pre+stones[i+1])
        );         
 
        return dp[i]=ans; 
    } 

    int stoneGameVIII(vector<int>& stones) { 
        int n=stones.size(); 
        dp.assign(n,INT_MIN);
                         
        return getans(stones,1,stones[0]+stones[1]); 
    } 
};    