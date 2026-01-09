/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getans(TreeNode* root, int& maxd, int curd, TreeNode*& r) {
        if(!root) return 0;

        int leftd = getans(root->left, maxd, curd + 1, r);
        int rightd = getans(root->right, maxd, curd + 1, r);

        maxd = max(maxd, curd);

        if(leftd == rightd && curd + leftd == maxd){
            r = root;
        }

        if(curd == maxd){
            r = root;
        }

        return max(leftd, rightd) + 1;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* r = nullptr;
        int maxd = 0;  
        getans(root, maxd, 0, r);
        return r;
    }
};