class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total=0;
        for(auto v:nums){
            total+=v;
        }

        int left=0;
        int n=nums.size();

        int cnt=0;

        for(int i=0;i<n;i++){
            left+=nums[i];
            if(left==(total-left) && !nums[i]){
                cnt+=2;
            }
            else if(abs(left-(total-left))==1 && !nums[i]){
                cnt++;
            }
        }

        return cnt;
    }
};