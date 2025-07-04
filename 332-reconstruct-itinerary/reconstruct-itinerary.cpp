class Solution {
public:
    vector<string> ans;
    unordered_map<string,vector<string>> adj;
    void dfs(string node){
        while(adj[node].size()){
            string nei=adj[node].back();
            adj[node].pop_back();
            dfs(nei);
        }

        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto t:tickets){
            adj[t[0]].push_back(t[1]);
        }

        for(auto &p:adj){
            sort(p.second.rbegin(),p.second.rend());
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};