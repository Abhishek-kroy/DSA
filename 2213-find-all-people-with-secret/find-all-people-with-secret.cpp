class Solution {
public:
    static bool op(vector<int>& a,vector<int>& b){ 
        return a[2]<b[2];
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(),meetings.end(),op);
        unordered_set<int> s;
        s.insert(0);
        s.insert(firstPerson);
        for(int i=0;i<meetings.size();i++){
            int t=meetings[i][2];
            unordered_map<int,vector<int>> adj;
            int j=i;
            while(j<meetings.size() && meetings[j][2]==t){
                int u=meetings[j][0];
                int v=meetings[j][1];      
                adj[u].push_back(v);
                adj[v].push_back(u);
                j++;
            }
            i=j-1;

            queue<int> q;
            unordered_set<int> visited;
            for(auto p:adj){
                if(s.find(p.first)!=s.end()){
                    q.push(p.first);
                    visited.insert(p.first); 
                }
            }

            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto nei:adj[node]){
                    if(visited.find(nei)==visited.end()){     
                        q.push(nei);
                        visited.insert(nei);
                        s.insert(nei);
                    }
                }
            }
        }
        vector<int> ans(s.begin(),s.end());

        return ans;      
    }
};