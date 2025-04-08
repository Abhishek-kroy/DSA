class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int l=-1;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                l=max(l,m[nums[i]]);
                cout<<l<<endl;
            }
            m[nums[i]]=i;
        }

        return ((l+3)/3);
    }
};