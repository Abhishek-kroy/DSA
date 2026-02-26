class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(nums[1]<=nums[0]){
            return false;
        }
        int i=2;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }

        i--;  

        if(i>(n-3)){
            return false;
        }

        if(i<n && nums[i+1]>=nums[i]){
            return false   ; 
        }

        i++;

        while(i<n &&   nums[i]<nums[i-1]){       
            i++;  
        }

        i--;

        if(i>(n-2)){
            return false;
        }

        i++;

        while(i<n && nums[i]>nums[i-1]){  
            i++;
        }

        if(i==n){
            return true;
        }

        return false ; 
        
    }
};