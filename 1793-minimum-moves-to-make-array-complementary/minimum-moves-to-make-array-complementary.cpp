class Solution {
public:

    int minMoves(vector<int>& nums,int limit) {

        int n=nums.size();

        vector<int> v(2*limit+2,0);

        for(int i=0;i<n/2;i++){

            int v1=nums[i];
            int v2=nums[n-1-i];

            int left=min(v1,v2)+1;
            int right=max(v1,v2)+limit;            

            v[2]+=2;
            v[left]-=2;

            v[right+1]+=2;
            v[2*limit+1]-=2;

            v[left]+=1;
            v[right+1]-=1; 
        }

        for(int i=2;i<=2*limit;i++){
            v[i]=v[i]+v[i-1];
        }

        for(int i=0;i<n/2;i++){

            int v1=nums[i];
            int v2=nums[n-1-i];

            v[v1+v2]-=1;
        }

        int ans=n;

        for(int i=2;i<=2*limit;i++){
            ans=min(ans,v[i]);
        }

        return ans;    
    }
};   