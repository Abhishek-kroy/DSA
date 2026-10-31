class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {

        int ith=nums[0];
        int jth=INT_MIN;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            jth=nums[i]-i;
            ans=max(ans,ith+jth);
            if(nums[i]+i>=ith){
                ith=nums[i]+i;
            }
        }
        return ans;
    }
};