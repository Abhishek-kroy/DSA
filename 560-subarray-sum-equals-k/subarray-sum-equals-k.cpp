class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> s;
        s[0]=1;

        int sum=0;

        int ans=0;    

        for(int i=0;i<n;i++){
            sum+=nums[i];


            ans+=s[sum-k];

            s[sum]++;

        }

        return ans;    
    }
};