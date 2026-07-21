class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOne = 0;
        for (char c : s)
            if (c == '1') totalOne++;
            
        s = "1" + s + "1";

        vector<pair<char,int>> runs;

        int i = 0, n = s.size();
        while (i < n) {
            char c = s[i];
            int cnt = 0;
            while (i < n && s[i] == c) {
                cnt++;
                i++;
            }

            if (c == '1') {
                if (runs.empty()) cnt--;      
                if (i == n) cnt--;            
            }

            runs.push_back({c, cnt});
        }

        int ans = totalOne;  

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                ans = max(ans,
                          totalOne + runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ans;
    }
};