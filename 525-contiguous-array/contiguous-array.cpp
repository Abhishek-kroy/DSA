class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> f;
        f[0]=-1;

        int cnt=0;

        int ans=0; 

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt--;
            }
            else{
                cnt++;
            }

            if(f.find(cnt)!=f.end()){
                ans=max(ans,i-f[cnt]);
            }
            else{
                f[cnt]=i;
            }
        }

        return ans;    

    }
};