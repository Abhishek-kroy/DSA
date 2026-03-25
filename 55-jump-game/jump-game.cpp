class Solution {
public:
    bool getans(vector<int>& nums,int i,vector<int>& dp){
        int n=nums.size();
        if(i==n-1)  return true;

        if(dp[i]!=-1)   return dp[i];

        bool ans=false;

        for(int j=1;j<=nums[i];j++){
            if(getans(nums,i+j,dp)){
                ans=true;
                break;
            }
        }

        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {

        int reach=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>reach){
                return false;
            }
            reach=max(reach,i+nums[i]);
        }

        return true; 


















    //    int reachable = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (i > reachable) return false;
    //         reachable = max(reachable, i + nums[i]);
    //     }
    //     return true;
    
    }
};