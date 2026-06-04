class Solution {
public:
    bool check(char n1, char n2, char n3){
        return (n2>n1 && n2>n3) || (n2<n1 && n2<n3); 
    }
    map<tuple<int, string, bool, bool>, pair<long long, long long>> dp;

    pair<long long, long long> getans(string& num, int i, string res,
                                      bool tight, bool started) {

        int n = num.size();

        if (i >= n) {
            return {1, 0};
        }

        auto key = make_tuple(i, res, tight, started);

        if (dp.count(key)) {
            return dp[key];
        }

        long long ans = 0;
        long long cnt = 0;

        int l = tight ? num[i] - '0' : 9;

        for (int j = 0; j <= l; j++) {

            bool ntight = tight && (j == num[i] - '0');
            bool nstarted = started || (j != 0);

            if (started || nstarted) {

                string r = res + to_string(j);

                auto s = getans(num, i + 1, r, ntight, nstarted);

                int add = 0;

                int t = r.size() - 1;

                if (r.size() >= 3 && check(r[t - 2], r[t - 1], r[t])) {
                    add = 1;
                }

                ans += 1LL * add * s.first + s.second;
                cnt += s.first;
            } else {

                auto s = getans(num, i + 1, "", ntight, nstarted);

                ans += s.second;
                cnt += s.first;
            }
        }

        return dp[key] = {cnt, ans};
    }

    int totalWaviness(int num1, int num2) {
        num1--; string str1=to_string(num1); string str2=to_string(num2); 

        dp.clear();
        auto a = getans(str2, 0, "", true, false).second;

        dp.clear();
        auto b = getans(str1, 0, "", true, false).second;

        return a - b;
    } 
};