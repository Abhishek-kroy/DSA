class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();

        vector<pair<int,int>> v;        

        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end());
        int i=0;

        priority_queue<pair<int,int>> pq;

        int ans=0;

        while(k>0){
            while(i<n && v[i].first<=w){
                pq.push({v[i].second,i});         
                i++;                               
            }

            if(!pq.empty()){
                auto [t,ind]=pq.top();
                pq.pop();

                w+=max(0,(t));
                k--;
            }
            else{
                break;
            }
        }

        return w;
    }
};