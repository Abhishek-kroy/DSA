class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<int> s1;
        multiset<int> s2;
        long long sum = 0;
        long long score = 0;

        for (int i = 0; i < k; i++) score += nums[i];

        int n = nums.size();
        int i = 1, j = 1;

        while (j < n) {  


            if (s1.size() < (k - 1)) {
                s1.insert(nums[j]);
                sum += nums[j];
            }
            else {
                int lar = *prev(s1.end());

                if (nums[j] >= lar) {
                    s2.insert(nums[j]);
                }
                else {
                    s1.erase(s1.find(lar));
                    sum -= lar;

                    s1.insert(nums[j]);
                    sum += nums[j];

                    s2.insert(lar);
                }
            }

            
            if ((j - i) == dist) {

                if (s1.size() < (k - 1)) {
                    j++;
                    continue;
                }

                score = min(score, nums[0] + sum);

                int val = nums[i];

                if (s2.find(val) != s2.end()) {
                    s2.erase(s2.find(val));
                }
                else {
                    s1.erase(s1.find(val));
                    sum -= val;

                    if (!s2.empty()) {
                        int ele = *s2.begin();
                        s2.erase(s2.begin());

                        s1.insert(ele);
                        sum += ele;
                    }
                }

                i++;
            }

            j++;
        }

        return score;
    }
};  