class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        
        // Count frequency of each element
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        // Print frequency map
        // cout << "Frequency Map:" << endl;
        // for (auto &p : m) {
        //     cout << p.first << " -> " << p.second << endl;
        // }

        unordered_map<int, unordered_set<int>> m1;
        unordered_map<int, int> m2;

        for (int i = 0; i < n; i++) {
            // cout << "\nStep " << i << ": Processing " << nums[i] << endl;

            if (m1[m2[nums[i]]].find(nums[i]) != m1[m2[nums[i]]].end()) {
                m1[m2[nums[i]]].erase(nums[i]);
                // cout << "Removed " << nums[i] << " from m1[" << m2[nums[i]] << "]" << endl;
            }

            m2[nums[i]]++;
            m1[m2[nums[i]]].insert(nums[i]);

            // cout << "m2[" << nums[i] << "] = " << m2[nums[i]] << endl;
            // cout << "m1[" << m2[nums[i]] << "] contains: ";
            // for (int x : m1[m2[nums[i]]]) cout << x << " ";
            // cout << endl;

            int leftFreq = m2[nums[i]];
            int rightFreq = m[nums[i]] - m2[nums[i]];
            int leftSize = i + 1;
            int rightSize = n - i - 1;

            // cout << "Checking condition: leftFreq=" << leftFreq 
            //      << " (needed>=" << (leftSize / 2 + 1) << "), rightFreq=" << rightFreq 
            //      << " (needed>=" << (rightSize / 2 + 1) << ")\n";

            if (m1[m2[nums[i]]].size() == 1 && 
                leftFreq >= (leftSize / 2 + 1) && 
                rightFreq >= (rightSize / 2 + 1)) {
                // cout << "Returning index: " << i << endl;
                return i;
            }
        }

        // cout << "No valid index found, returning -1\n";
        return -1;
    }
};