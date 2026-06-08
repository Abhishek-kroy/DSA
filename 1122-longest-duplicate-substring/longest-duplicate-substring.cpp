class Solution {
public:
    long long power(long long a, long long n) {
        long long res = 1;
        int mod = (int)1e9 + 7;

        while (n > 0) {    
            if (n & 1) {
                res = (res * a) % mod;    
            }
            a = (a * a) % mod;
            n = n >> 1;            
        }        

        return res; 
    }

    string check(string& s, int len) {
        if (len <= 0) return "";

        int i = 0;
        int j = 0;
        int n = s.size();

        long long b = 31;        
        long long b2 = 37;        
        long long mod = (int)1e9 + 7; 

        long long pow = power(b, len - 1);
        long long pow2 = power(b2, len - 1);

        long long f1 = 0; 
        long long f2 = 0;  

        unordered_map<long long, int> f; 

        while (j < n) {
            if (j - i + 1 > len) {
                f1 = (f1 - ((s[i] - 'a' + 1) * pow) % mod + mod) % mod;
                f2 = (f2 - ((s[i] - 'a' + 1) * pow2) % mod + mod) % mod;
                i++; 
            }

            f1 = (f1 * b + (s[j] - 'a' + 1)) % mod;      
            f2 = (f2 * b2 + (s[j] - 'a' + 1)) % mod;      

            if (j - i + 1 == len) {
                long long combined_key = (f1 << 30) | f2;
                f[combined_key]++;

                if (f[combined_key] >= 2) {
                    return s.substr(i, len);
                }
            }  

            j++; 
        }    

        return "";    
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 1;        
        int r = n - 1;
        string ans = "";

        while (l <= r) {
            int mid = l + (r - l) / 2;
            string res = check(s, mid);

            if (!res.empty()) {
                ans = res;
                l = mid + 1;        
            }
            else {
                r = mid - 1;
            }
        }

        return ans;
    }
}; 