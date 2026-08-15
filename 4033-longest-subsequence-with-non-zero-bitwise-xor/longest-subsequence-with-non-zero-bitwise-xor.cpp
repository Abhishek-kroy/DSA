class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonzero=false;

        int n=nums.size();

        int v=0;

        for(int i=0;i<n;i++){
            if(v){
                nonzero=true;          
            }
            v=v^nums[i];        
        }

        if(v!=0){
            return n;
        }

        if(nonzero){
            return n-1;
        }

        return 0; 
    }
};