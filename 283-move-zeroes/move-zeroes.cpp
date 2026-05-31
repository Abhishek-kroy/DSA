class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n=nums.size();

        int i=-1;          

        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                i++;  
                swap(nums[i],nums[j]);                            
            }
        }        
        
    }
};