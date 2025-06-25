class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> s;
        int n=nums.size();
        unordered_map<int,int> m;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            // cnt+=(m[nums[i]-k]+m[nums[i]+k]);
            if(m[nums[i]-k]>0 && s.find({nums[i],nums[i]-k})==s.end()){
                s.insert({nums[i],nums[i]-k});
                s.insert({nums[i]-k,nums[i]});
                cnt++;
            }
            if(m[nums[i]+k]>0 && s.find({nums[i],nums[i]+k})==s.end()){
                s.insert({nums[i],nums[i]+k});
                s.insert({nums[i]+k,nums[i]});
                cnt++;
            }
            m[nums[i]]++;
            // cout<<cnt<<endl;
        }
        return cnt;
    }
};