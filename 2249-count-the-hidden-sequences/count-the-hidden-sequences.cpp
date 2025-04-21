#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<unsigned long long> prefix;
        prefix.push_back(0);
        int n = differences.size();
        long long min_ele = 0, max_ele = 0;

        for (int i = 0; i < n; i++) {
            unsigned long long current = prefix.back() + differences[i];
            prefix.push_back(current);
            min_ele = min(min_ele, (long long)current);
            max_ele = max(max_ele, (long long)current);
        }

        long long n1 = (long long)lower - min_ele;
        long long n2 = (long long)upper - max_ele;

        int result = max(0LL, n2 - n1 + 1);

        return result;
    }
};