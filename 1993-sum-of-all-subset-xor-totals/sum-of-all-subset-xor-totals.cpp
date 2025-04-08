class Solution {
public:
    void getans(vector<int>& nums,int i,int s,int &sum){
        if(i>=nums.size()){
            sum+=s;
            return ;
        }

        // take
        getans(nums,i+1,s^nums[i],sum);
        // not take
        getans(nums,i+1,s,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        getans(nums,0,0,sum);
        return sum;
    }
};