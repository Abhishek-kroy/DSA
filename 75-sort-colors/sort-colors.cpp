class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int z=-1;    
        int t=n;

        for(int i=0;i<t;i++){    
            if(nums[i]==0){
                z++;  
                swap(nums[z],nums[i]);      
            }                        
            if(nums[i]==2){
                t--;
                swap(nums[i],nums[t]);        
                i--; 
            }
        }
    }
};