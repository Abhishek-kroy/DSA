#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // dp[x][y][turned][dir]
    vector<vector<vector<vector<int>>>> dp;
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}; // ++,+-,--,-+
    
    int getans(int x, int y, bool turned, int val, vector<vector<int>>& grid, int dir) {
        int n = grid.size(), m = grid[0].size();
        
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != val) {
            return 0;
        }

        int &res = dp[x][y][turned][dir];
        if (res != -1) return res;

        // Continue straight
        int len1 = 1 + getans(x + dirs[dir][0], y + dirs[dir][1], turned, (val + 2) % 4, grid, dir);

        // Try one turn (only if not already turned)
        if (!turned) {
            int nextDir = (dir + 1) % 4; // clockwise turn
            len1 = max(len1, 1 + getans(x + dirs[nextDir][0], y + dirs[nextDir][1], true, (val + 2) % 4, grid, nextDir));
        }

        return res = len1;
    }

    int getval(int i, int j, vector<vector<int>>& grid) {
        return 1 + max({
            getans(i + 1, j + 1, false, 2, grid, 0), // "++"
            getans(i + 1, j - 1, false, 2, grid, 1), // "+-"
            getans(i - 1, j - 1, false, 2, grid, 2), // "--"
            getans(i - 1, j + 1, false, 2, grid, 3)  // "-+"
        });
    }

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.assign(n, vector<vector<vector<int>>>(
                        m, vector<vector<int>>(
                               2, vector<int>(4, -1))));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, getval(i, j, grid));
                }
            }
        }
        return ans;
    }
};