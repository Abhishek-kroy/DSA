class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

        int i=nums[0];
        int j=nums[nums[0]];

        while(i!=j){

            cout<<i<<" "<<j<<endl; 

            i=nums[i];
            j=nums[nums[j]];
        }

        i=0;

        while(i!=j){
            i=nums[i];
            j=nums[j];
        }    

        return i;  
    }
};