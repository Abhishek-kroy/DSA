class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        vector<int> netR(n, 0), netU(n, 0);

        netR[0] = (s[0] == 'R' ? 1 : (s[0] == 'L' ? -1 : 0));
        netU[0] = (s[0] == 'U' ? 1 : (s[0] == 'D' ? -1 : 0));

        for (int i = 1; i < n; i++) {
            netR[i] = netR[i - 1] + (s[i] == 'R' ? 1 : (s[i] == 'L' ? -1 : 0));
            netU[i] = netU[i - 1] + (s[i] == 'U' ? 1 : (s[i] == 'D' ? -1 : 0));
        }

        unordered_set<long long> st;  

        for (int i = 0; i <= n - k; i++) {
            int r = (i > 0 ? netR[i - 1] : 0) + (netR[n - 1] - netR[i + k - 1]);
            int u = (i > 0 ? netU[i - 1] : 0) + (netU[n - 1] - netU[i + k - 1]);
            long long key=((1LL*r)<<32 ^ (1LL*u));   
            st.insert(key);  
        }

        return st.size();
    }
}; 