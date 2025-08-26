class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        int z=0;
        int ans=0;
        while(r<n){
            if(nums[r]==0){
                z++;
            }
            int end=r-1;
            while(z==2){
                ans=max(ans,r-l);
                if(nums[l]==0)  z--;

                l++;
            }
            r++;
        }
        ans=max(ans,r-l);

        return ans-1;
    }
};