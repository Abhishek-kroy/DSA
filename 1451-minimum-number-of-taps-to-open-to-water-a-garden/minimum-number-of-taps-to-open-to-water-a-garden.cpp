class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> nums;

        for(int i=0;i<=n;i++){
            nums.push_back({i-ranges[i],i+ranges[i]});
        }

        sort(nums.begin(),nums.end());

        priority_queue<int> pq;

        int st=0;

        int cnt=0;

        int ptr=0;

        while(st<n){
            // cout<<"entered "<<endl;            
            while(ptr<=n && nums[ptr][0]<=st){
                pq.push(nums[ptr][1]);
                // cout<<"pushed "<<nums[ptr][1]<<endl;
                ptr++;
            }

            if(pq.empty()){
                return -1;
            }

            int end=pq.top();
            pq.pop();

            if(end<=st){
                return -1;
            }

            cnt++;

            // cout<<"st updated to "<<end<<endl;         

            st=end;
        }

        return cnt;        
    }
};