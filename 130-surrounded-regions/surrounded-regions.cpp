class Solution {
public:
    void bfs(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        board[x][y] = 'T';
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i - 1 >= 0 && board[i - 1][j] == 'O') {
                board[i - 1][j] = 'T';
                q.push({i - 1, j});
            }
            if (i + 1 < board.size() && board[i + 1][j] == 'O') {
                board[i + 1][j] = 'T';
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && board[i][j - 1] == 'O') {
                board[i][j - 1] = 'T';
                q.push({i, j - 1});
            }
            if (j + 1 < board[0].size() && board[i][j + 1] == 'O') {
                board[i][j + 1] = 'T';
                q.push({i, j + 1});
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Start BFS from 'O's on the border and mark them as 'T'
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') {
                bfs(board, 0, j);
            }
            if (board[rows - 1][j] == 'O') {
                bfs(board, rows - 1, j);
            }
        }
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') {
                bfs(board, i, 0);
            }
            if (board[i][cols - 1] == 'O') {
                bfs(board, i, cols - 1);
            }
        }

        // Flip all remaining 'O's to 'X's and 'T's back to 'O's
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
