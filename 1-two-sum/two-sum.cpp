class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end() && m[target-nums[i]]!=i){
                return {m[target-nums[i]],i};
            }
            m[nums[i]]=i;
        }

        return {};
    }
};