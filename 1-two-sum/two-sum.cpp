class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<nums.size();i++){
            v[i]={nums[i],i};
        }

        sort(v.begin(),v.end());
        int i=0;
        int j=n-1;

        while(i<j){
            if(v[i].first+v[j].first==target) return {v[i].second,v[j].second};
            else if(v[i].first+v[j].first>target) j--;
            else i++;
        }

        return {};
    }
};