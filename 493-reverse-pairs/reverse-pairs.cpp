class Solution {
public:
    int mergesort(vector<int>& nums,int l,int r){
        if(l==r){
            return 0;
        }

        int mid=(l+r)/2;

        int left=mergesort(nums,l,mid);
        int right=mergesort(nums,mid+1,r);

        int ans=left+right;    

        int i=l;
        int j=mid+1;

        int ptr=0;    

        vector<int> res(r-l+1);

        for(int k=j;k<=r;k++){
            int cnt=abs((lower_bound(nums.begin()+l,nums.begin()+j,1LL*2*nums[k]+1)-(nums.begin()+mid+1)));       

            ans+=cnt;    
        }

        while(i<=mid && j<=r){
            if(nums[i]<=nums[j]){
                res[ptr]=nums[i];
                i++;     
            }
            else{
                res[ptr]=nums[j];
                j++;
            }

            ptr++;    
        }

        while(i<=mid){
            res[ptr]=nums[i];
            i++;
            ptr++;
        }
        while(j<=r){
            res[ptr]=nums[j];    
            j++;
            ptr++;
        }

        for(int k=0;k<r-l+1;k++){    
            nums[l+k]=res[k];
        }
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};