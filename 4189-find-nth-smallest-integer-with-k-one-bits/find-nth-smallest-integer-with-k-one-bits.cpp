// const int N = 52;
class Solution {
public:
    // long long fact[N], invfact[N];

    // long long power(long long a, long long b) {
    //     long long res = 1;
    //     while (b) {
    //         if (b & 1) {
    //             res = (res * a) % MOD;
    //         }
    //         a = (a * a) % MOD;
    //         b >>= 1;
    //     }

    //     return res;
    // }

    // void init() {

    //     fact[0] = 1;

    //     for (int i = 1; i < N; i++) {
    //         fact[i] = (fact[i - 1] * i) % MOD;
    //     }

    //     invfact[N - 1] = power(fact[N - 1], MOD - 2);

    //     for (int i = N - 2; i >= 0; i--) {
    //         invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    //     }
    // }

    // int nCr(int n, int r) {
    //     if (n < 0 || r > n || r < 0) {
    //         return 0;
    //     }
    //     return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    // }  

    long long comb(int n, int r, long long lim) {
        if (r < 0 || r > n)
            return 0;
        r = min(r, n - r);

        __int128 res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > lim)
                return lim;
        }

        return (long long)res;
    }

    long long nthSmallest(long long n, int k) {

        // init();  

        // 111
        // 1011
        // 1101
        // 1110

        string str = "";
        for (int i = 0; i < 51; i++) {
            str += '0';
        }

        int l = 51;

        while (k > 0) {
            long long prev = 0;
            for (int i = k; i < l; i++) {
                // long long curr = nCr(i - 1, k - 1);
                long long curr = comb(i - 1, k - 1,n);  
                // cout << "k=" << k
                //     << " i=" << i
                //     << " curr=" << curr
                //     << " prev=" << prev
                //     << " n=" << n << endl;
                if (prev + curr >= n) {
                    l = i;
                    str[i] = '1';
                    n -= prev;
                    break;
                } else {
                    prev += curr;
                }
            }
            k--;
        }

        // cout<<str<<endl;

        long long ans = 0;

        for (int i = 1; i < 51; i++) {
            if (str[i] == '1') {
                ans += (1LL << (i - 1));
            }
        }

        return ans;
    }
};