class Solution {
public:
    void getans(vector<int>& jobs,int i,int k,vector<long long>& worker,int& ans){
        if(i>=jobs.size()){
            int val=*max_element(worker.begin(),worker.end());
            ans=min(ans,val);
            return ;
        }
        int val=*max_element(worker.begin(),worker.end());
        if(val>=ans)
            return ;
        
        for(int j=0;j<k;j++){
            if(j>0 and worker[j]==worker[j-1]){
                continue ;
            }
            worker[j]+=jobs[i];
            getans(jobs,i+1,k,worker,ans);
            worker[j]-=jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        // NOTES
        // sort(jobs.rbegin(), jobs.rend());
        vector<long long> worker(k,0);
        int ans=INT_MAX;
        getans(jobs,0,k,worker,ans);
        return ans;
    }
};