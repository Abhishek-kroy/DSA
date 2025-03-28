class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int val=nums[i];
            if(m.find(target-val)!=m.end()){
                return {m[target-val],i};
            }
            m[val]=i;
        }
        return {-1,-1};
    }
};