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
        // getans(nums,0,0,sum);
        // return sum;
        vector<int> v;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            int k=v.size();
            for(int j=0;j<k;j++){
                v.push_back(nums[i]^v[j]);   
                sum+=nums[i]^v[j];
            }
            sum+=nums[i];
            v.push_back(nums[i]);
        }

        return sum;
    }
};