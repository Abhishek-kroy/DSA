#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int n, B;
    vector<int> present, future;
    vector<vector<int>> tree;
    vector<vector<vector<int>>> dp; // dp[u][pb][b]

    int maxProfit(int N, vector<int>& pres, vector<int>& fut,
                  vector<vector<int>>& hierarchy, int budget) {
        n = N;
        B = budget;
        present = pres;
        future = fut;
        tree.assign(n, {});
        for (auto &e : hierarchy) {
            tree[e[0]-1].push_back(e[1]-1);
        }

        dp.assign(n, vector<vector<int>>(2, vector<int>(B+1, 0)));
        vector<int> indeg(n, 0);
        for (int u = 0; u < n; ++u)
            for (int v : tree[u]) indeg[v]++;

        // Topo-order via Kahn
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (int v : tree[u]) if (--indeg[v] == 0) q.push(v);
        }

        // process in reverse topo (children first)
        for (int idx = (int)topo.size()-1; idx >= 0; --idx) {
            int u = topo[idx];
            for (int pb = 0; pb < 2; ++pb) {
                // option1: skip u
                vector<int> base(B+1, 0);
                for (int v : tree[u]) {
                    vector<int> nxt(B+1, 0);
                    auto &childDP = dp[v][0];
                    for (int b1 = 0; b1 <= B; ++b1) {
                        if (b1 > 0 && base[b1] == 0) continue;
                        for (int b2 = 0; b1 + b2 <= B; ++b2) {
                            nxt[b1 + b2] = max(nxt[b1 + b2], base[b1] + childDP[b2]);
                        }
                    }
                    base.swap(nxt);
                }
                for (int b = 0; b <= B; ++b)
                    dp[u][pb][b] = base[b];

                // option2: buy u
                int price = pb ? present[u]/2 : present[u];
                if (price <= B) {
                    int gain = future[u] - price;
                    vector<int> base2(B+1, 0);
                    for (int v : tree[u]) {
                        vector<int> nxt(B+1, 0);
                        auto &childDP = dp[v][1];
                        for (int b1 = 0; b1 <= B; ++b1) {
                            if (b1 > 0 && base2[b1] == 0) continue;
                            for (int b2 = 0; b1 + b2 <= B; ++b2) {
                                nxt[b1 + b2] = max(nxt[b1 + b2], base2[b1] + childDP[b2]);
                            }
                        }
                        base2.swap(nxt);
                    }
                    for (int b = price; b <= B; ++b) {
                        dp[u][pb][b] = max(dp[u][pb][b], base2[b - price] + gain);
                    }
                }
            }
        }

        return *max_element(dp[0][0].begin(), dp[0][0].end());
    }
};