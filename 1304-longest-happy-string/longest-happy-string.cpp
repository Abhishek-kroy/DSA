class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
         priority_queue<pair<int, char>> pq;

        if (a) pq.push({a, 'a'});    
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto [f, ch] = pq.top();
            pq.pop();

            int n = ans.size();

            if (n >= 2 && ans[n-1] == ch && ans[n-2] == ch) {
                if (pq.empty()) break;

                auto [f2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                f2--;

                if (f2 > 0)
                    pq.push({f2, ch2});

                pq.push({f, ch});
            }
            else {
                ans += ch;
                f--;

                if (f > 0)
                    pq.push({f, ch});
            }
        }

        return ans;
    }
};