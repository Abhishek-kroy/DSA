class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int i=0;

        int end=i;

        while(i<n && end>=i){
            end=max(end,i+nums[i]);
            i++;
        }

        return end>=n-1;
    }
};