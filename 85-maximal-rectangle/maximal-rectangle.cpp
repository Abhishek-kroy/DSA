#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;

        
        int m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) {
                    if (matrix[i][j] == '1') {
                        prefix[i][j] = 1;
                    }
                } else {
                    if (matrix[i][j] == '1') {
                        prefix[i][j] = 1 + prefix[i][j + 1];
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    int cnt = 0;
                    int width=prefix[i][j];
                    for (int k = i; k < n and width>0; k++) {
                        cnt++;
                        width=min(width,prefix[k][j]);
                        ans = max(ans, cnt * width);
                    }
                }
            }
        }

        return ans;
    }
};