class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        long long ans=0;
        unordered_map<int,int> m;
        long long comb=0;

        for(int i=0;i<nums.size();i++){
            int v=m[nums[i]];
            comb-=(v*(v-1))/2;
            m[nums[i]]++;
            v=m[nums[i]];
            comb+=(v*(v-1))/2;
            while (comb >= k && j<i) {
                ans+=nums.size()-i;
                v=m[nums[j]];
                comb-=(v*(v-1))/2;
                m[nums[j]]--;
                v=m[nums[j]];
                comb+=(v*(v-1))/2;
                j++;
            }
        }

        return ans;
    }
};