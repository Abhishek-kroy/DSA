using namespace std;

class Solution {
    vector<int> prefix;

public:
    Solution() {
        prefix.resize(10002);
        int cnt = 0;

        for (int v = 0; v <= 10001; v++) {
            string val = to_string(v);
            int s1 = 0, s2 = 0;

            if (val.size() % 2 == 0) {
                int mid = val.size() / 2;
                for (int i = 0; i < mid; i++) s1 += (val[i] - '0');
                for (int i = mid; i < val.size(); i++) s2 += (val[i] - '0');

                if (s1 == s2) cnt++;
            }

            prefix[v] = cnt;
        }
    }

    int countSymmetricIntegers(int low, int high) {
        return prefix[high] - prefix[low - 1];
    }
};