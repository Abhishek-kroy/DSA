class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    int m, n, K;
    vector<vector<int>> grid;

    // memo[i][j][turns][dir]
    vector<vector<vector<vector<ll>>>> memo;

    ll dfs(int i, int j, int turns, int prevDir) {
        if (turns > K)
            return INF;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        ll &res = memo[i][j][turns][prevDir];
        if (res != -1)
            return res;

        res = INF;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dr[dir];
            int nj = j + dc[dir];

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;

            int newTurns = turns;

            if (prevDir != 4 && prevDir != dir)
                newTurns++;

            res = min(res, (ll)grid[i][j] +
                            dfs(ni, nj, newTurns, dir));
        }

        return res;
    }

    int minCost(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        K = k;

        memo.assign(
            m,
            vector<vector<vector<ll>>>(
                n,
                vector<vector<ll>>(k + 1, vector<ll>(5, -1))
            )
        );

        ll ans = dfs(0, 0, 0, 4);

        return ans >= INF ? -1 : (int)ans;
    }
};