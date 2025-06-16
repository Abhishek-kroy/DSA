class Solution {
public:
    bool getans(vector<int>& nums,int k,int target,int mask,int sum,vector<int> &dp){
        int n=nums.size();
        if(k==0){
            return true;
        }

        if(dp[mask]!=-1){
            return dp[mask];
        }

        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                int newsum=sum+nums[i];
                if(newsum>target) continue;
                int newmask=mask|(1<<i);

                if(newsum==target){
                    if(getans(nums,k-1,target,newmask,0,dp)){
                        return dp[mask]=true;
                    }
                }
                else{
                    if(getans(nums,k,target,newmask,newsum,dp)){
                        return dp[mask]=true;
                    }

                }
            }
        }

        return dp[mask]=false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> dp(1<<n,-1);
        long long total=0;
        for(auto v:nums){
            total+=v;
        }

        if(total%k){
            return false;
        }

        total/=k;

        return getans(nums,k,total,0,0,dp);
    }
};