#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
        // cout << "DSU initialized, size = " << n << "\n";
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        // cout << "  unite(" << a << ", " << b << ")\n";

        if (a == b) {
            // cout << "    already in same set\n";
            return;
        }

        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];

        // cout << "    parent[" << b << "] = " << a
        //      << ", size = " << sz[a] << "\n";
    }

    bool same(int a, int b) {
        bool ok = find(a) == find(b);
        // cout << "  same(" << a << ", " << b << ") = " << ok << "\n";
        return ok;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        DSU* left  = new DSU((row+1)*(col+1)+2);
        // DSU* right = new DSU((row+1)*(col+1)+2);

        int leftv = -1;
        int rightv = -1;

        unordered_set<int> iswater;
        int day = 1;

        for (auto cell : cells) {
            int r = cell[0];
            int c = cell[1];
            int v1 = col * r + c;

            // cout << "\nDay " << day
            //      << " flooding cell (" << r << "," << c << ") id=" << v1 << "\n";

            if (c == 1) {
                if (leftv == -1) {
                    leftv = v1;
                    // cout << "  left boundary first water id=" << leftv << "\n";
                } else {
                    left->unite(leftv, v1);
                }
            }

            if (c == col) {
                if (rightv == -1) {
                    rightv = v1;
                    // cout << "  right boundary first water id=" << rightv << "\n";
                } else {
                    left->unite(rightv, v1);
                }
            }

            iswater.insert(v1);

            vector<int> dx = {0,1,1,1,0,-1,-1,-1};
            vector<int> dy = {1,1,0,-1,-1,-1,0,1};

            for (int i = 0; i < 8; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];

                if (nx >= 1 && nx <= row && ny >= 1 && ny <= col) {
                    int value = col * nx + ny;
                    if (iswater.find(value) != iswater.end()) {
                        // cout << "  neighbor water at ("
                        //      << nx << "," << ny << ") id=" << value << "\n";
                        left->unite(value, v1);
                        // right->unite(value, v1);
                    }
                }
            }

            if (leftv != -1 && rightv != -1) {
                // cout << "Checking connectivity leftv=" << leftv
                //      << " rightv=" << rightv << "\n";
                if (left->same(leftv, rightv)) {
                    // cout << "CONNECTED on day " << day-1 << "\n";
                    return day - 1;
                }
            }

            day++;
        }

        return -1;
    }
}; 