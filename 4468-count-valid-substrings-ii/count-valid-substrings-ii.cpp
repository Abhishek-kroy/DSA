class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        long long total = 1LL * n * (n + 1) / 2;
        long long invalid = 0;

        int a = -1, ab = -1;
        bool abc=false;
        int abci=-1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a = i;

            if (s[i] == 'b' && a != -1) ab = a;

            if (s[i] == 'c' && ab != -1){
                invalid += ab + 1;
                abci=ab;
                abc=true;
            }
            else if(abc){
                invalid+=abci+1;
            }
        }

        return total - invalid;
    }
};