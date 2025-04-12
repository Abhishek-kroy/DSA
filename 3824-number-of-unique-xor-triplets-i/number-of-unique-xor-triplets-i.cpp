class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int cnt=0;
        for(int i=nums.size();i>0;i/=2){
            cnt++;
        }

        return pow(2,cnt);
    }
};