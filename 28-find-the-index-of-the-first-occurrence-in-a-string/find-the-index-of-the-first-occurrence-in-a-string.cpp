class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;

        int base = 31;
        int mod = 1e9 + 7;
        int n = needle.size();

        // Hash of needle
        long long target = 0;
        for (char c : needle) {
            target = (target * base + (c - 'a' + 1)) % mod;
        }

        // power = base^(n-1)
        long long power = 1;
        for (int i = 0; i < n; i++) { 
            power = (power * base) % mod;
        }

        long long hash = 0;
        int i = 0;

        for (int j = 0; j < haystack.size(); j++) {

            // ALWAYS add current character
            hash = (hash * base + (haystack[j] - 'a' + 1)) % mod;

            // Shrink window if too large
            if (j - i + 1 > n) {
                hash = (hash - (haystack[i] - 'a' + 1) * power % mod + mod) % mod;
                i++;
            }

            // Check match
            if (j - i + 1 == n && hash == target) {
                if (haystack.substr(i, n) == needle)
                    return i;
            }
        }

        return -1;
    }
}; 