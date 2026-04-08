class Solution {
public:
    class cmp{
        public:
            bool operator()(vector<int>& a,vector<int>& b){
                if(a[0]!=b[0]){
                    return a[0]>b[0];
                }

                return a[1]>b[1];   
            }
    };

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<vector<int>> v(n,vector<int> (2));

        for(int i=0;i<n;i++){
            v[i]={nums2[i],nums1[i]};
        }

        sort(v.begin(),v.end(),cmp());

        priority_queue<int,vector<int>,greater<int>> pq;

        long long ans=0;

        long long sum=0;

        for(int i=0;i<n;i++){
            if(pq.size()<k){
                sum+=v[i][1];
                pq.push(v[i][1]);
            }
            else{
                ans=max(ans,1LL*sum*v[i][0]);   
                if(pq.top()<v[i][1]){
                    sum-=pq.top();
                    pq.pop();
                    sum+=v[i][1];
                    pq.push(v[i][1]);
                }
            }
            
            if(pq.size()==k)
                ans=max(ans,1LL*sum*v[i][0]);   
        }

        return ans;   
    }
};