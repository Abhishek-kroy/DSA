class Solution {
public:
    long long mergesort(vector<long long>& pre,int l,int r,int low,int up){
        if(l>=r){
            return 0;
        }

        int mid=l+(r-l)/2;

        long long ans=0;

        ans+=mergesort(pre,l,mid,low,up);
        ans+=mergesort(pre,mid+1,r,low,up);

        int p1=mid+1;
        int p2=mid+1;

        for(int i=l;i<=mid;i++){
            while(p1<=r && pre[p1]<pre[i]+low){
                p1++;
            }

            while(p2<=r && pre[p2]<=pre[i]+up){
                p2++;
            }

            ans+=(p2-p1);
        }

        vector<long long> tmp;

        int i=l;
        int j=mid+1;

        while(i<=mid && j<=r){
            if(pre[i]<=pre[j]){
                tmp.push_back(pre[i++]);
            }
            else{
                tmp.push_back(pre[j++]);
            }
        }

        while(i<=mid){
            tmp.push_back(pre[i++]);
        }

        while(j<=r){
            tmp.push_back(pre[j++]);
        }

        for(int k=0;k<(int)tmp.size();k++){
            pre[l+k]=tmp[k];
        }

        return ans;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();

        vector<long long> pre(n+1,0);

        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }

        return mergesort(pre,0,n,lower,upper);
    }
}; 