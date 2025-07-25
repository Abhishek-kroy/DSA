class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n);
        // vector<int> suf(n);
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        // suf[n-1]=1;
        int suf=nums[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=suf*pre[i];
            suf=suf*nums[i];
        }

        return pre;

        // 1  2  3 4
        // 1  1  2 6
        // 24 12 4 1
        // 1  1  2 6

        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     ans[i]=pre[i]*suf[i];
        // }

        // -1  1  0 -3 3
        //  1 -1 -1  0 0
        //  0  0 -9 3 1

        // return ans;
    }
};