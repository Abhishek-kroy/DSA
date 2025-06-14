class Solution {
public:
    unordered_map<string, int> dp;

    int getans(vector<string>& stickers, string& target, string mask, vector<vector<int>>& stickerCounts, vector<int>& targetCount) {
        if (mask.find('0') == string::npos) return 0;
        if (dp.count(mask)) return dp[mask];

        int n = stickerCounts.size();
        int res = 1e5;

        for (int i = 0; i < n; i++) {
            string newMask = mask;
            vector<int> available = stickerCounts[i];

            bool used = false;
            for (int j = 0; j < target.size(); j++) {
                if (newMask[j] == '0' && available[target[j] - 'a'] > 0) {
                    newMask[j] = '1';
                    available[target[j] - 'a']--;
                    used = true;
                }
            }

            if (!used) continue;

            int sub = getans(stickers, target, newMask, stickerCounts, targetCount);
            if (sub != 1e5)
                res = min(res, 1 + sub);
        }

        return dp[mask] = res;
    }

    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> stickerCounts;
        unordered_set<char> s;

        for (const string& st : stickers) {
            vector<int> cnt(26, 0);
            for (char c : st) {
                cnt[c - 'a']++;
                s.insert(c);
            }
            stickerCounts.push_back(cnt);
        }

        vector<int> targetCount(26, 0);
        for (char c : target) {
            targetCount[c - 'a']++;
            if (s.find(c) == s.end()) return -1;
        }

        string mask(target.size(), '0');
        int result = getans(stickers, target, mask, stickerCounts, targetCount);
        return result == 1e5 ? -1 : result;
    }
};