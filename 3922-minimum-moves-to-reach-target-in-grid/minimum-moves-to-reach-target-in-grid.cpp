#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

class Solution {
    int sx, sy, tx, ty;
    queue<pii> q1, q2;
    map<pii, int> d1, d2;

    bool inBounds(int x, int y) {
        return x >= sx && x <= tx && y >= sy && y <= ty;
    }

public:
    int minMoves(int _sx, int _sy, int _tx, int _ty) {
        sx = _sx;
        sy = _sy;
        tx = _tx;
        ty = _ty;

        if (sx == tx && sy == ty) return 0;

        q1.push({sx, sy});
        d1[{sx, sy}] = 0;
        q2.push({tx, ty});
        d2[{tx, ty}] = 0;

        while (!q1.empty() && !q2.empty()) {
            if (q1.size() <= q2.size()) {
                cout << "Forward depth: " << d1.size()
                     << ", Current front: (" << q1.front().first << ", " << q1.front().second << ")\n";
                int sz = q1.size();
                while (sz--) {
                    auto [x, y] = q1.front(); q1.pop();
                    int dist = d1[{x, y}];
                    int s = max(x, y);

                    pii p1 = {x + s, y};
                    if (!inBounds(p1.first, p1.second)) {
                        cout << "  Out of bounds (forward): (" << p1.first << ", " << p1.second << ")\n";
                    } else if (!d1.count(p1)) {
                        cout << "  Adding (forward): (" << p1.first << ", " << p1.second << "), dist = " << dist + 1 << "\n";
                        if (d2.count(p1)) {
                            cout << "Meeting point: (" << p1.first << ", " << p1.second << ")\n";
                            return dist + d2[p1] + 1;
                        }
                        q1.push(p1);
                        d1[p1] = dist + 1;
                    }

                    pii p2 = {x, y + s};
                    if (!inBounds(p2.first, p2.second)) {
                        cout << "  Out of bounds (forward): (" << p2.first << ", " << p2.second << ")\n";
                    } else if (!d1.count(p2)) {
                        cout << "  Adding (forward): (" << p2.first << ", " << p2.second << "), dist = " << dist + 1 << "\n";
                        if (d2.count(p2)) {
                            cout << "Meeting point: (" << p2.first << ", " << p2.second << ")\n";
                            return dist + d2[p2] + 1;
                        }
                        q1.push(p2);
                        d1[p2] = dist + 1;
                    }
                }
            } else {
                cout << "Backward depth: " << d2.size()
                     << ", Current front: (" << q2.front().first << ", " << q2.front().second << ")\n";
                int sz = q2.size();
                while (sz--) {
                    auto [x, y] = q2.front(); q2.pop();
                    int dist = d2[{x, y}];

                    auto tryPush = [&](pii p) {
                        if (!inBounds(p.first, p.second)) {
                            cout << "  Out of bounds (backward): (" << p.first << ", " << p.second << ")\n";
                        } else if (!d2.count(p)) {
                            cout << "  Adding (backward): (" << p.first << ", " << p.second << "), dist = " << dist + 1 << "\n";
                            if (d1.count(p)) {
                                cout << "Meeting point: (" << p.first << ", " << p.second << ")\n";
                                return dist + d1[p] + 1;
                            }
                            q2.push(p);
                            d2[p] = dist + 1;
                        }
                        return -1;
                    };

                    int res = -1;
                    if (x % 2 == 0 && x / 2 >= y) res = tryPush({x / 2, y});
                    if (res != -1) return res;
                    if (x >= y && (x-y)<=y) res = tryPush({x - y, y});
                    if (res != -1) return res;
                    if (y % 2 == 0 && y / 2 >= x) res = tryPush({x, y / 2});
                    if (res != -1) return res;
                    if (y >= x && (y-x)<=x) res = tryPush({x, y - x});
                    if (res != -1) return res;
                }
            }
        }

        cout << "No path found.\n";
        return -1;
    }
};