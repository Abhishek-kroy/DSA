class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int target=0; 

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(i>0){
                if(nums[i-1]==nums[i]){
                    continue; 
                }
            }

            int j=i+1;
            int k=n-1;

            while(j<k){
                if(j>i+1 && nums[j]==nums[j-1]){    
                    j++; 
                    continue;
                }
                int sum=nums[j]+nums[k];
                if(sum==target-nums[i]){
                    ans.push_back({nums[i],nums[j],nums[k]}); 
                    j++; 
                }
                else if(sum>target-nums[i]){
                    k--;
                }
                else{
                    j++; 
                }
            }
        }

        return ans; 
    }
};