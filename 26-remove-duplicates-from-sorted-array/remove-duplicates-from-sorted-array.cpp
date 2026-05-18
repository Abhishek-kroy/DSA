class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int n=nums.size();

        int cnt=1;

        while(j<n){
            if(nums[i]!=nums[j]){
                cnt++;
                i++;
                swap(nums[i],nums[j]);
            }            
            j++;
        }

        return cnt; 
    }
};