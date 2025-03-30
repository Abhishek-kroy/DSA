#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        // Precompute longest palindromic substring lengths starting at each index in s.
        // We'll compute a DP table for s where dp[i][j] is true if s[i..j] is a palindrome.
        vector<vector<bool>> dp_s(n, vector<bool>(n, false));
        vector<int> palS(n, 1); // at least every char is a palindrome of length 1.
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i < 2 || dp_s[i+1][j-1])) {
                    dp_s[i][j] = true;
                    palS[i] = max(palS[i], j - i + 1);
                }
            }
        }
        
        // Precompute longest palindromic substring lengths ending at each index in t.
        // We compute dp for t and store in palT the max palindrome ending at j.
        vector<vector<bool>> dp_t(m, vector<bool>(m, false));
        vector<int> palT(m, 1); // each char is a palindrome of length 1.
        for (int j = 0; j < m; j++) {
            for (int i = j; i >= 0; i--) {
                if(t[i] == t[j] && (j - i < 2 || (i+1 <= j-1 && dp_t[i+1][j-1]))) {
                    dp_t[i][j] = true;
                    palT[j] = max(palT[j], j - i + 1);
                }
            }
        }
        
        // Determine the best palindrome already in s or t.
        int best = 0;
        for (int i = 0; i < n; i++) {
            best = max(best, palS[i]);
        }
        for (int j = 0; j < m; j++) {
            best = max(best, palT[j]);
        }
        
        // Reverse t to work with common prefix computation.
        string t_rev = t;
        reverse(t_rev.begin(), t_rev.end());
        
        // Precompute LCP table between s and t_rev.
        // LCP[i][j] = longest common prefix of s[i:] and t_rev[j:].
        vector<vector<int>> lcp(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if(s[i] == t_rev[j])
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                else
                    lcp[i][j] = 0;
            }
        }
        
        // Try to build palindromes by combining a common substring from s and reversed t,
        // and then possibly extending either in s (with palS) or in t (with palT).
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int common = lcp[i][j];
                if(common == 0) continue;
                int currLen = 2 * common; // even length palindrome
                best = max(best, currLen);
                
                // Try extending with a palindrome in s: use palS starting at i+common (if exists).
                if(i + common < n) {
                    best = max(best, currLen + palS[i + common]);
                }
                // Extend on the other side using palindrome from t.
                // Map position in t_rev to original t:
                // t_rev[j ... j+common-1] corresponds to t[ m - 1 - (j+common-1) ... m - 1 - j ].
                // So the character before this block in t is at index: m - 1 - (j+common) 
                int tPos = m - 1 - (j + common);
                if(tPos >= 0) {
                    best = max(best, currLen + palT[tPos]);
                }
            }
        }
        
        return best;
    }
};