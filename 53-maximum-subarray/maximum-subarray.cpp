class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=INT_MIN;
        int i=0;
        int csum=0;
        while(i<nums.size()){
            csum+=nums[i];
            sum=max(sum,csum);
            if(csum<0){
                csum=0;
            }

            i++;
        }

        return sum;
    }
};