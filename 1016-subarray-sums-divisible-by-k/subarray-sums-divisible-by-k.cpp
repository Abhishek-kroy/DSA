class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();

        int ans=0;

        unordered_map<int,int> f;

        f[0]=1;

        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            sum=(((sum)%k+k)%k);    

            if(f.find(sum)==f.end()){    
                f[sum]=1; 
            }
            else{
                ans+=f[sum];
                f[sum]++;
            }

        }

        return ans;    
    }
};