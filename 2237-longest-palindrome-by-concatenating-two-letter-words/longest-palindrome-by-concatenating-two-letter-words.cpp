#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, unordered_set<int>> m;
        unordered_set<int> used;

        // Store all indices for each word
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].insert(i);
        }

        int count = 0;
        bool centerUsed = false;

        for (int i = 0; i < words.size(); ++i) {
            if (used.count(i)) continue;

            string word = words[i];
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (m.count(rev)) {
                for (int j : m[rev]) {
                    if (j != i) {
                        count += 4;
                        used.insert(i);
                        used.insert(j);
                        m[word].erase(i);
                        m[rev].erase(j);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < words.size(); ++i) {
            if (!used.count(i) && words[i][0] == words[i][1]) {
                count += 2;
                break;
            }
        }

        return count;
    }
};