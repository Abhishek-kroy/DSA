class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];

            for(int i=l;i<=r;i+=k){
                nums[i]=(1LL*nums[i]*v)%((int)1e9+7);   
            }
        }

        int x=0;
        for(auto v:nums){
            x=x^v;
        }

        return x; 
    }
};