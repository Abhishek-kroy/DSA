class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int n=-1;
        for(auto v:nums){
            if(n==-1){
                n=v;
                cnt=1;
            }
            else if(v==n){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    n=-1;
                }
            }
        }

        return n;
    }
};