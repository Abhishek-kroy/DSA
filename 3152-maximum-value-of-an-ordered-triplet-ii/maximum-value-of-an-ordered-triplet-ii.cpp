class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> largest(nums.size()-1);
        int val=nums.back();
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            largest[i]=val;
            val=max(val,nums[i]);
        }

        val=nums[0];

        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,1LL*(val-nums[i])*1LL*largest[i]);
            val=max(val,nums[i]);
        }


        return ans;
    }
};