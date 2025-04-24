class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt=0;
        unordered_set<int> s;
        for(auto i:nums){
            if(s.find(i)==s.end()){
                cnt++;
                s.insert(i);
            }
        }

        int i=0;
        int j=0;
        int c=0;
        int ans=0;
        vector<int> f(2001,0);
        while(j<nums.size()){
            f[nums[j]]++;
            if(f[nums[j]]==1){
                c++;
            }
            while(c==cnt){
                ans+=nums.size()-j;
                f[nums[i]]--;
                if(f[nums[i]]==0){
                    c--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};