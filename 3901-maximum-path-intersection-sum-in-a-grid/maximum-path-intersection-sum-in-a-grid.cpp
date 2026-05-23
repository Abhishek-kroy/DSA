#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;

        // 1. Check all Rows
        for (int i = 0; i < m; i++) {
            int st = 0;
            int sum = 0;
            for (int end = 0; end < n; end++) {
                sum += grid[i][end];

                if (st == end) {
                    // Check if this single element sits on any 2D grid boundary
                    if (i == 0 || i == m - 1 || end == 0 || end == n - 1) {
                        int current_max = INT_MIN;
                        // Try expanding to the left neighbor if available
                        if (end > 0) {
                            current_max = max(current_max, grid[i][end] + grid[i][end - 1]);
                        }
                        // Try expanding to the right neighbor if available
                        if (end < n - 1) {
                            current_max = max(current_max, grid[i][end] + grid[i][end + 1]);
                        }
                        ans = max(ans, current_max);
                    } else {
                        // Safe internal cell of length 1
                        ans = max(ans, sum);
                    }
                } else {
                    // Standard segment of length >= 2
                    ans = max(ans, sum);
                }

                // Kadane's window reset
                if (sum < 0) {
                    sum = 0;
                    st = end + 1;
                }
            }
        }

        // 2. Check all Columns
        for (int j = 0; j < n; j++) {
            int st = 0;
            int sum = 0;
            for (int end = 0; end < m; end++) {
                sum += grid[end][j];

                if (st == end) {
                    // Check if this single element sits on any 2D grid boundary
                    if (end == 0 || end == m - 1 || j == 0 || j == n - 1) {
                        int current_max = INT_MIN;
                        // Try expanding to the top neighbor if available
                        if (end > 0) {
                            current_max = max(current_max, grid[end][j] + grid[end - 1][j]);
                        }
                        // Try expanding to the bottom neighbor if available
                        if (end < m - 1) {
                            current_max = max(current_max, grid[end][j] + grid[end + 1][j]);
                        }
                        ans = max(ans, current_max);
                    } else {
                        // Safe internal cell of length 1
                        ans = max(ans, sum);
                    }
                } else {
                    // Standard segment of length >= 2
                    ans = max(ans, sum);
                }

                // Kadane's window reset
                if (sum < 0) {
                    sum = 0;
                    st = end + 1;
                }
            }
        }

        return ans;
    }
};   