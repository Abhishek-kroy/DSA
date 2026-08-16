class Solution {
public:
    unordered_map<int,int> dp;
    int getans(vector<int>& sto,int i){
        int n=sto.size();
        if(i>=n){
            return 0;
        }

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }

        int ans=INT_MIN;
        int sum=0;
        for(int j=0;j<3 && i+j<n;j++){
            sum+=sto[i+j];
            ans=max(ans,sum-getans(sto,i+j+1));
        }

        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans=getans(stoneValue,0);
        if(ans>0){
            return "Alice";
        }
        else if(ans==0){
            return "Tie";
        }

        return "Bob";          
    }
};