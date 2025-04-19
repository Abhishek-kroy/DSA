class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)   {
            int j1=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int j2=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            ans+=j2-j1;
        }
        return ans;
    }
};