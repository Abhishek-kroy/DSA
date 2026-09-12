class Solution {
    long long base = 313;
    long long mod1 = 1e9 + 7;
    long long mod2 = 1e9 + 9;
    vector<long long> h1, h2, p1, p2;

    void buildHashes(const string& s, int n) {
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * base) % mod1;
            p2[i + 1] = (p2[i] * base) % mod2;

            h1[i + 1] = (h1[i] * base + s[i]) % mod1;
            h2[i + 1] = (h2[i] * base + s[i]) % mod2;
        }
    }

    pair<long long, long long> getHash(int l, int r) {
        long long hash1 = (h1[r + 1] - (h1[l] * p1[r - l + 1]) % mod1 + mod1) % mod1;
        long long hash2 = (h2[r + 1] - (h2[l] * p2[r - l + 1]) % mod2 + mod2) % mod2;
        return {hash1, hash2};
    }

    int getLCP(int i, int j, int max_len) {
        int low = 1, high = max_len, lcp = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getHash(i, i + mid - 1) == getHash(j, j + mid - 1)) {
                lcp = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lcp;
    }

public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        buildHashes(s, n);

        int i = 0;
        int ones = 0;
        int best_start = -1;
        int min_len = n + 1;

        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                ones++;
            }

            while (ones > k || (ones == k && s[i] == '0')) {
                if (s[i] == '1') {
                    ones--;
                }
                i++;
            }

            if (ones == k) {
                int cur_len = j - i + 1;

                if (cur_len < min_len) {
                    min_len = cur_len;
                    best_start = i;
                } else if (cur_len == min_len) {
                    int lcp = getLCP(best_start, i, cur_len);
                    if (lcp < cur_len) {
                        if (s[i + lcp] < s[best_start + lcp]) {
                            best_start = i;
                        }
                    }
                }
            }
        }

        if (best_start == -1) {
            return "";
        }

        return s.substr(best_start, min_len);
    }
};