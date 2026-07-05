class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n=nums.size();

        int v=nums[n/2];

        if(n==1){
            return true;
        }   

        for(int i=0;i<n;i++){
            if(i==n/2){
                continue;
            }

            if(nums[i]==v){
                return false; 
            }
        }

        return true; 
    }
};