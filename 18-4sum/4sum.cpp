class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());         

        vector<vector<int>> ans;

        int n=nums.size(); 

        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue; 
            }

            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j-1]==nums[j]){
                    continue; 
                }

                int k=j+1;

                int l=n-1;

                while(k<l){
                    if(k>j+1 && nums[k-1]==nums[k]){
                        k++; 
                        continue;
                    }

                    long long sum=1LL*nums[i]+1LL*nums[j]+1LL*nums[k]+1LL*nums[l];

                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        k++; 
                    }
                }

            }
        }

        return ans;    
    }
};