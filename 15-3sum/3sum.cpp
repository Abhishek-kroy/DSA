class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int val=nums[i];
            int target=-val;

            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[k]});    
                    j++;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    k--;
                    while(k>j && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }

            }           


        }   

        return ans  ;                
    }
};

// -4 -1 -1 0 1 2