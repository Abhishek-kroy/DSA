class node {
public:
    node* ch[2];
    node() {
        ch[0] = nullptr;
        ch[1] = nullptr;
    }    
};

class trie {
public:
    node* root;

    trie() {
        root = new node();
    }

    void insert(int num) {
        node* tmp = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!tmp->ch[bit]) {
                tmp->ch[bit] = new node();
            }
            tmp = tmp->ch[bit];
        }
    }

    int getMaxXor(int x) {
        node* tmp = root;
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int toggled_bit = 1 - bit;         
            
            if (tmp->ch[toggled_bit]) {
                max_xor |= (1 << i);
                tmp = tmp->ch[toggled_bit];
            } else {
                tmp = tmp->ch[bit];
            }
        }
        return max_xor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q_size = queries.size();

        vector<vector<int>> offlineQueries(q_size, vector<int>(3));
        for (int i = 0; i < q_size; i++) {
            offlineQueries[i][0] = queries[i][1]; 
            offlineQueries[i][1] = queries[i][0]; 
            offlineQueries[i][2] = i;              
        }

        sort(nums.begin(), nums.end());
        sort(offlineQueries.begin(), offlineQueries.end());

        trie* t = new trie();
        vector<int> ans(q_size);
        int nums_idx = 0;
        int n = nums.size();

        for (int i = 0; i < q_size; i++) {
            int m = offlineQueries[i][0];
            int x = offlineQueries[i][1];
            int original_idx = offlineQueries[i][2];

            while (nums_idx < n && nums[nums_idx] <= m) {
                t->insert(nums[nums_idx]);
                nums_idx++;
            }

            if (nums_idx == 0) {
                ans[original_idx] = -1;    
            } else {
                ans[original_idx] = t->getMaxXor(x);
            }
        }

        return ans;
    }
}; 