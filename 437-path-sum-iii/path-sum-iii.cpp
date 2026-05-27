/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getans(TreeNode* root, int targetsum, unordered_map<long long, int>& sum,
               long long s) {
        if (!root) {
            return 0;
        }

        int w1 = 0;

        s += root->val;

        if (sum.find(s - targetsum) != sum.end()) {
            w1 += sum[s - targetsum];
        }

        sum[s]++;

        w1 = w1 + getans(root->left, targetsum, sum, s)+getans(root->right, targetsum, sum, s);

        sum[s]--;

        return w1;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> sum;
        sum[0] = 1;
        return getans(root, targetSum, sum, 0);
    }
};