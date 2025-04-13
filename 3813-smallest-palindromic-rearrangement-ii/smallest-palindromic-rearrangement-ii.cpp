class Solution {
public:
    string smallestPalindrome(string s, int k) {
        string mid = "";
        if (s.size() % 2 == 1) {
            mid = string(1, s[s.size() / 2]);
        }

        vector<int> cnt(26, 0);
        for (int i = 0; i < s.size(); i++) {
            if (s.size() % 2 == 1 && i == s.size() / 2) {
                continue;
            }
            cnt[s[i] - 'a']++;
        }

        // Only need half the counts since we'll form the first half, then second half is mirrored
        for (int i = 0; i < 26; i++) {
            cnt[i] /= 2;
        }

        string out = "";

        for (int i = 0; i < s.size() / 2; i++) {
            bool found = false;
            for (int j = 0; j < 26; j++) {
                // Try the first available char
                if (cnt[j] > 0) {
                    cnt[j]--; // Use this as the next char

                    long long ways = 1;
                    int letters = accumulate(cnt.begin(), cnt.end(), 0);
                    for (int freq : cnt) {
                        if (freq > 0) {
                            ways *= comb(letters, freq); // Calculate combinations
                            letters -= freq;
                        }
                        if (ways >= k) {
                            break;
                        }
                    }

                    if (ways >= k) {
                        out.push_back('a' + j);
                        found = true;
                        break;
                    }

                    // Update ways we've passed
                    k -= ways;
                    cnt[j]++; // Add back to count if this isn't the next char
                }
            }

            // No valid option
            if (!found) {
                return "";
            }
        }

        // Combine the first half with the second half
        string second_half = out;
        reverse(second_half.begin(), second_half.end());

        return out + mid + second_half;
    }

private:
    // Helper function to compute combinations nCr
    long long comb(int n, int r) {
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;
        r = min(r, n - r); // Take advantage of symmetry
        long long res = 1;
        for (int i = 0; i < r && res<=1000000; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }
};