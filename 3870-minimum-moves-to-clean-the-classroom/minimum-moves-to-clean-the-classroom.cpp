class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        
        queue<vector<int>> q;
        int x, y;
        int l = 0;
        
        unordered_map<int, int> ltom;
        int ms = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    x = i;
                    y = j;
                }
                else if (classroom[i][j] == 'L') {
                    l++;
                    ltom[i * m + j] = ms;
                    ms <<= 1;
                }
            }
        }
        
        q.push({x, y, energy, 0});
        
        vector<vector<vector<int>>> maxEnergy(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << l, -1)
            )
        );
        
        maxEnergy[x][y][0] = energy;
        
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        
        int level = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                vector<int> v = q.front();
                q.pop();
                
                int i = v[0];
                int j = v[1];
                int e = v[2];
                int mask = v[3];
                
                if (mask == (1 << l) - 1) {
                    return level;
                }
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m || classroom[ni][nj] == 'X') {
                        continue;
                    }
                    
                    int ne = e - 1;
                    int nm = mask;
                    
                    if (ne < 0) {
                        continue;
                    }
                    
                    if (classroom[ni][nj] == 'L') {
                        nm |= ltom[ni * m + nj];
                    }
                    
                    if (classroom[ni][nj] == 'R') {
                        ne = energy;
                    }
                    
                    if (ne > maxEnergy[ni][nj][nm]) {
                        maxEnergy[ni][nj][nm] = ne;
                        q.push({ni, nj, ne, nm});
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
};