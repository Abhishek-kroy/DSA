class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int v=prices[n-1];
        int ans=0;
        for(int i=n-2;i>=0;i--){
            ans=max(ans,v-prices[i]);
            v=max(v,prices[i]);
        }

        return ans;
    }
};