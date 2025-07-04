class Solution {
public:
    int getans(vector<int>& edges, vector<bool>& visited, int node) {
        int nod = node;
        unordered_map<int, int> parent;

        while (nod != -1 && !visited[nod]) {
            visited[nod] = true;

            if (edges[nod] != -1) {
                parent[edges[nod]] = nod;
            }

            nod = edges[nod];
        }

        if (nod == -1 || edges[nod]==-1) {
            return 0;
        }

        if (!parent.count(nod)) {
            return 0;
        }

        unordered_set<int> nei;
        int len = 0;

        while (nei.find(nod) == nei.end()) {
            if (!parent.count(nod)) {
                return 0;
            }
            nei.insert(nod);
            nod = parent[nod];
            len++;
        }
        
        return len;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans = max(ans, getans(edges, visited, i));
            }
        }

        return ans == 0 ? -1 : ans;
    }
};