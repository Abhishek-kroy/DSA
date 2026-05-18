class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int i=0;
        int j=n-1;
        int k=n-1;

        while(i<=j){
            int v1=nums[i]*nums[i];
            int v2=nums[j]*nums[j];

            if(v1>=v2){
                ans[k]=v1;
                i++;                         
            }
            else{
                ans[k]=v2;
                j--;
            }
            k--;
        }

        return ans;   
    }
};