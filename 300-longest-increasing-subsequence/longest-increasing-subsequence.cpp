class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        int n=nums.size();

        for(int i=0;i<n;i++){
            int v=nums[i];
            auto it=lower_bound(ans.begin(),ans.end(),v);
            if(it!=ans.end()){
                *it=v;
            }
            else{
                ans.push_back(v);
            }
        }

        return ans.size();
    }
};