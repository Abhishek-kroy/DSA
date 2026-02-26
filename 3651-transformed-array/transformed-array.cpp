class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);

        for(int i=0;i<n;i++){
            int ind=((i+nums[i])%n+n)%n;
            res[i]=nums[ind];
        }

        return res  ;  
    }
};