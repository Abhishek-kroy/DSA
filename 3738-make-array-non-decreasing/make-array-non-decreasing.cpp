class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int change=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                change++;
                nums[i]=nums[i-1];
            }
        }

        return n-change;
    }
};