
class Solution {
public:
    using ll = long long;

    vector<vector<int>> adj;
    vector<int> sz;
    vector<ll> R, D, B, best;

    void dfs(int u, int p, string& colors) {
        sz[u] = 1;

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, colors);
            sz[u] += sz[v];
        }

        ll flipR = (colors[u] == 'R' ? 0 : sz[u]);
        ll flipB = (colors[u] == 'B' ? 0 : sz[u]);

        ll sumB = 0;

        R[u] = flipR;
        B[u] = flipB;
        best[u] = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            R[u] += min(R[v], B[v]);
            B[u] += B[v];

            sumB += B[v];

            best[u] = min(best[u],
                          min(best[v], R[v] - B[v]));
        }

        D[u] = flipB + sumB + best[u];
    }

    long long minCost(int n, string colors,
                      vector<vector<int>>& edges) {
        adj.assign(n, {});
        sz.assign(n, 0);
        R.assign(n, 0);
        D.assign(n, 0);
        B.assign(n, 0);
        best.assign(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, colors);

        return min({R[0], D[0], B[0]});
    }
};        