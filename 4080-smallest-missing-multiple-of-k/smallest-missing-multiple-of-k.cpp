class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]%k==0){
                int ci=nums[i]/k-1;

                if(ci>=0 && ci<n && nums[i]!=nums[ci]){
                    swap(nums[ci],nums[i]);
                }
                else{
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)*k){
                return (i+1)*k;
            }
        }

        return (n+1)*k;
    }
};