class Solution {
public:
    long long mergesort(vector<int>& pre, int i, int j){

        if(i>=j)
            return 0;

        int mid=i+(j-i)/2;

        long long cnt=0;

        cnt+=mergesort(pre,i,mid);
        cnt+=mergesort(pre,mid+1,j);

        int p1=i;
        int p2=mid+1;

        // Count pairs
        while(p2<=j){

            while(p1<=mid && pre[p1]<pre[p2])
                p1++;

            cnt+=(p1-i);

            p2++;
        }

        // Merge
        vector<int> res;

        p1=i;
        p2=mid+1;

        while(p1<=mid && p2<=j){

            if(pre[p1]<=pre[p2]){
                res.push_back(pre[p1]);
                p1++;
            }
            else{
                res.push_back(pre[p2]);
                p2++;
            }
        }

        while(p1<=mid){
            res.push_back(pre[p1]);
            p1++;
        }

        while(p2<=j){
            res.push_back(pre[p2]);
            p2++;
        }

        for(int k=i;k<=j;k++)
            pre[k]=res[k-i];

        return cnt;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n=nums.size();

        // n+1 prefix sums
        vector<int> pre(n+1,0);

        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+(nums[i-1]==target ? 1 : -1);
        }

        return mergesort(pre,0,n);
    }
}; 