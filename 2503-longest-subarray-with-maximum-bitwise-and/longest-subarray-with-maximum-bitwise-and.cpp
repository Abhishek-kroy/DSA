class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val=nums[0];
        int n=nums.size();
        int len=1;
        int cur_len=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                cur_len++;
            }
            else{
                cur_len=1;
            }
            if(nums[i]>max_val){
                len=cur_len;
            }
            else if(nums[i]==max_val){
                len=max(len,cur_len);
            }
            max_val=max(max_val,nums[i]);
        }

        return len;
    }
};