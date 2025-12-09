class Solution {
public:
    long long totalScore(long long hp, vector<int>& damage, vector<int>& requirement) {
        long long ans = 0; 
        long long n = damage.size();

        vector<long long> prefix(n+1,0);
        int j=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+damage[i-1];
        }

        for(int i=1;i<=n;i++){
            int t=prefix[i]-hp+(long long)requirement[i-1];  
            auto it = lower_bound(prefix.begin(), prefix.begin() + i, t);
            int idx = it - prefix.begin(); 
            ans += (i - idx);    
        }

        return ans; 
    }
}; 