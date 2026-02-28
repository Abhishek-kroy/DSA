class Solution {
public:
    // int getans(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,0);
    //     dp[n-1]=nums[n-1];

    //     for(int i=n-2;i>=0;i--){
    //         dp[i]=max(dp[i],nums[i]);
    //         dp[i]=max(dp[i],dp[i+1]);
    //         if(i+2<n){
    //             dp[i]=max(dp[i],nums[i]+dp[i+2]);
    //         }
    //     }

    //     return dp[0];
    // }

    int getans(vector<int>& nums,vector<int>& dp,int i){
        int n=nums.size();

        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];  
        }

        int w1=nums[i]+getans(nums,dp,i+2);
        int w2=getans(nums,dp,i+1);

        dp[i]=max(w1,w2);

        return dp[i];



    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> t(nums.begin(),nums.end()-1);
        vector<int> t1(nums.begin()+1,nums.end());

        vector<int> dp1(t.size()+1,-1);
        vector<int> dp2(t1.size()+1,-1);

        return max(getans(t,dp1,0),getans(t1,dp2,0));

        // return max(getans(t),getans(t1));
    }
};