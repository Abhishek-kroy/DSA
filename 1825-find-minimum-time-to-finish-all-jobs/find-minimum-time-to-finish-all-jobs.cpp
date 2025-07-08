class Solution {
public:
    // void getans(vector<int>& jobs,int i,int k,vector<long long>& worker,int& ans){
    //     if(i>=jobs.size()){
    //         int val=*max_element(worker.begin(),worker.end());
    //         ans=min(ans,val);
    //         return ;
    //     }
    //     int val=*max_element(worker.begin(),worker.end());
    //     if(val>=ans)
    //         return ;
        
    //     for(int j=0;j<k;j++){
    //         if(j>0 and worker[j]==worker[j-1]){
    //             continue ;
    //         }
    //         worker[j]+=jobs[i];
    //         getans(jobs,i+1,k,worker,ans);
    //         worker[j]-=jobs[i];
    //     }
    // }
    // int minimumTimeRequired(vector<int>& jobs, int k) {
    //     // NOTES
    //     // sort(jobs.rbegin(), jobs.rend());
    //     vector<long long> worker(k,0);
    //     int ans=INT_MAX;
    //     getans(jobs,0,k,worker,ans);
    //     return ans;
    // }
    bool canAssign(vector<int>& jobs, vector<int>& workers, int idx, int limit) {
    if (idx == jobs.size()) return true;

    for (int i = 0; i < workers.size(); ++i) {
        if (workers[i] + jobs[idx] <= limit) {
            workers[i] += jobs[idx];
            if (canAssign(jobs, workers, idx + 1, limit)) return true;
            workers[i] -= jobs[idx];

            // Prune if this worker hasn't taken any job
            if (workers[i] == 0) break;
        }
    }

    return false;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend()); // Try bigger jobs first
    int low = *max_element(jobs.begin(), jobs.end());
    int high = accumulate(jobs.begin(), jobs.end(), 0);
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> workers(k, 0);

        if (canAssign(jobs, workers, 0, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}
};