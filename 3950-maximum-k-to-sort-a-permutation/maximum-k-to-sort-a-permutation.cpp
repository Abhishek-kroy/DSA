class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                k=i&k;
            }
        }
        return k==INT_MAX ? 0 : k;
    }
};