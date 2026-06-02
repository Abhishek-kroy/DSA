class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr=0;

        int i=0; 

        for(auto v:nums){
            xr=xr^v; 
            xr=xr^i;

            i++; 
        }

        xr=xr^i;    

        return xr; 
    }
};