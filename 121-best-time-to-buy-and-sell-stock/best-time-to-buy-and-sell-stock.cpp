class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int st=prices[n-1];
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,st-prices[i]);
            st=max(st,prices[i]);
        }

        return ans;
    }
};