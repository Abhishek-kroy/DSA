class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1){
            return 1;   
        }
        
        int n=nums.size();

        int i=1;
        int j=2;
        while(j<n){
            if(nums[j]!=nums[i-1]){
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }

        return i+1;   
    }
};