class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<vector<int>> range(26, vector<int>(2, -1));

        int n = word.size();

        for (int i = 0; i < n; i++) {
            char s = word[i];

            if (s >= 'A' && s <= 'Z') {
                continue;
            }

            if (range[s - 'a'][0] == -1) {
                range[s - 'a'][0] = i;
            }

            range[s - 'a'][1] = i;
        }

        vector<int> f(26, -1);
        for (int i = 0; i < n; i++) {
            char s = word[i];        

            if (s >= 'a' && s <= 'z') {
                continue;
            }

            if (f[s - 'A'] == -1) {
                f[s - 'A'] = i;
            }
        }

        int cnt = 0;

        unordered_set<int> used;

        for (int i = 0; i < n; i++) {
            char c = word[i];

            if (used.find(c) != used.end()) {
                continue;
            }

            if (c >= 'A' && c <= 'Z') {
                continue;
            }

            int l = range[c - 'a'][0];
            int r = range[c - 'a'][1];

            int fi = f[c - 'a'];

            if (fi != -1 && r < fi) {
                cnt++;
                used.insert(c);
            }
        }

        return cnt;
    }
};      