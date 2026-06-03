class Solution {
public:
    int atmost(vector<int>& nums,int k){
        int n=nums.size();

        int i=0;
        int j=0;

        int ans=0;

        unordered_map<int,int> f;

        while(j<n){
            f[nums[j]]++;

            while(f.size()>k){
                f[nums[i]]--; 

                if(f[nums[i]]==0){
                    f.erase(nums[i]);
                }

                i++; 
            }

            ans+=(j-i+1);

            j++; 
        }

        return ans; 

    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmost(nums,k)-atmost(nums,k-1);
    }
};