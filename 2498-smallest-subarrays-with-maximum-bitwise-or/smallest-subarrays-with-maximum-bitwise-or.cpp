class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<long long> max_val(n,nums[n-1]);
        for(int i=n-2;i>=0;i--){
            max_val[i]=nums[i]|max_val[i+1];
        }

        vector<int> ans(n);
        vector<int> bits(32,0);

        int i=0;
        int j=0;
        int cur_val=0;
        while(j<n){
            cur_val|=nums[j];
            int v=nums[j];
            int pos=0;
            while(v){
                int b=v&1;
                bits[pos]+=b;
                pos++;
                v>>=1;
            }
            while (i <= j && cur_val == max_val[i]) {
                ans[i]=j-i+1;
                int v2=nums[i];
                int pos2=0;
                while(v2){
                    int b2=v2&1;
                    bits[pos2]-=b2;
                    if(bits[pos2]==0){
                        cur_val=cur_val&~(1<<pos2);
                    }
                    pos2++;
                    v2>>=1;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};