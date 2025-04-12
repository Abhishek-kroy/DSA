class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                s.insert(nums[i]^nums[j]);
            }
        }

        int cnt=0;
        for(int k=0;k<=2048;k++){
            for(auto v:nums){
                if(s.find(v^k)!=s.end()){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
};