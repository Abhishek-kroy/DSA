class Solution {
public:
    bool getans(vector<int>& nums,int sum,int mask,int csum,vector<int>& dp){
        int n=nums.size();
        if(mask==(1<<n)-1){
            return csum==0;
        }

        if(dp[mask]!=-1){
            return dp[mask];
        }

        for(int i=0;i<n;i++){
            if(!(mask&1<<i)){
                int nmask=mask|(1<<i);
                if(csum+nums[i]==sum){
                    bool ans=getans(nums,sum,nmask,0,dp);
                    if(ans){
                        return dp[mask]=ans;
                    }
                }
                else if(csum+nums[i]<sum){
                    bool ans=getans(nums,sum,nmask,csum+nums[i],dp);
                    if(ans){
                        return dp[mask]=ans;
                    }
                }
            }
        }

        return dp[mask]=false; 
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        long long tsum=0;
        for(auto v:nums){
            tsum+=v;
        }
        if(tsum%k){
            return false;
        }
        vector<int> dp((1<<n)+1,-1);
        return getans(nums,tsum/k,0,0,dp);
    }
};