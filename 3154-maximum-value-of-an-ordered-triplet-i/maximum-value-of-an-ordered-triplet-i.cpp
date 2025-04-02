class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> largest(n);
        int val=nums.back();
        for(int i=n-2;i>=0;i--){
            largest[i]=val;
            val=max(val,nums[i]);
        }
        
        int i_val=nums[0];
        long long ans=0;
        for(int j=1;j<n-1;j++){
            ans=max(ans,1LL*(1LL*i_val-1LL*nums[j])*1LL*largest[j]);
            i_val=max(i_val,nums[j]);
        }

        return ans;
    }
};