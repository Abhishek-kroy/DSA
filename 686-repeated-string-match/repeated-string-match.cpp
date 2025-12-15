class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;
        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        // search b inside s or s+a
        int base = 31;
        int mod = 1e9 + 7;

        int na = b.size();
        int nb = s.size();

        // hash of pattern (b)
        long long hash_a = 0;
        for (char c : b)
            hash_a = (hash_a * base + (c - 'a' + 1)) % mod;

        // precompute power = base^(na-1)
        long long power = 1; 
        for (int i = 0; i < na; i++) 
            power = (power * base) % mod;

        long long hash_b = 0;
        int i = 0;

        for (int j = 0; j < nb; j++) {

            // add new char
            hash_b = (hash_b * base + (s[j] - 'a' + 1)) % mod;

            // maintain window size
            if (j - i + 1 > na) {
                hash_b = (hash_b - (s[i] - 'a' + 1) * power % mod + mod) % mod;
                i++;
            }

            // check match
            if (j - i + 1 == na && hash_b == hash_a) {
                if (s.substr(i, na) == b)
                    return cnt;
            }
        }

        // check one extra repeat
        s += a;
        cnt++;

        hash_b = 0;
        i = 0;
        nb = s.size();

        for (int j = 0; j < nb; j++) {
            hash_b = (hash_b * base + (s[j] - 'a' + 1)) % mod;

            if (j - i + 1 > na) {
                hash_b = (hash_b - (s[i] - 'a' + 1) * power % mod + mod) % mod;
                i++;
            }

            if (j - i + 1 == na && hash_b == hash_a) {
                if (s.substr(i, na) == b)
                    return cnt;
            }
        }

        return -1;
    }
}; 