#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans;
        long long sum1 = 0;
        int z1 = 0;
        long long sum2 = 0;
        int z2 = 0;

        for (auto i : nums1) {
            sum1 += i;
            if (!i) z1++;
        
        
        }

        cout<<sum1<<endl;

        for (auto i : nums2) {
            sum2 += i;
            if (!i) {
                z2++;
            }
        }
        cout<<sum2<<endl;

        if (sum2+z2 > sum1+z1) {
            if(!z1){
                return -1;
            }
            long long val = sum2 - sum1 + z2;
            return sum2 + z2;
        }

        if (sum1+z1 > sum2+z2) {
            if(!z2){
                return -1;
            }
            long long val = sum1 - sum2 + z1;
            return sum1 + z1;
        }

        return max(sum1 + z1, sum2 + z2);
    }
};