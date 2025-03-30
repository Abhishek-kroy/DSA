class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int totalLand = 0, reachableLand = 0;
        queue<pair<int, int>> q;

        // Count total land cells and push boundary 1s to queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) totalLand++; 
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2; // Mark boundary land cells as visited
                }
            }
        }

        // BFS directions (4-way movement)
        vector<int> x_dir = {-1, 1, 0, 0};
        vector<int> y_dir = {0, 0, -1, 1};

        // Perform BFS from boundary `1`s
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            reachableLand++; // Count land cells that can reach boundary

            for (int k = 0; k < 4; k++) {
                int nx = x + x_dir[k];
                int ny = y + y_dir[k];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = 2; // Mark visited
                }
            }
        }

        return totalLand - reachableLand; // Only surrounded land cells
    }
};
