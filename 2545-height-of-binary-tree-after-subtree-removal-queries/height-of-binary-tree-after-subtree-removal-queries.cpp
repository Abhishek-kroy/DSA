class Solution {
public:
    unordered_map<int,int> depth;      // depth from root
    unordered_map<int,int> subH;       // subtree height
    unordered_map<int, pair<int,int>> bestAtDepth; 
    // bestAtDepth[d] = {max1, max2}

    // ---------- DFS to compute depth + subtree height ----------
    int dfs(TreeNode* root, int d){
        if(!root) return -1;

        depth[root->val] = d;

        int left = dfs(root->left, d+1);
        int right = dfs(root->right, d+1);

        subH[root->val] = max(left, right) + 1;

        // initialize if not present
        if(!bestAtDepth.count(d))
            bestAtDepth[d] = {-1, -1};

        // update best two heights at this depth
        auto &p = bestAtDepth[d];
        int h = subH[root->val];

        if(h > p.first){
            p.second = p.first;
            p.first = h;
        } 
        else if(h > p.second){
            p.second = h;
        }

        return subH[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        depth.clear();
        subH.clear();
        bestAtDepth.clear();

        dfs(root, 0);   // fill all tables

        vector<int> ans;

        for(int u : queries){
            int d = depth[u];
            int myH = subH[u];

            int max1 = bestAtDepth[d].first;
            int max2 = bestAtDepth[d].second;

            // ---- YOUR RULE ----
            if(max2 == -1){  
                // ONLY ONE NODE at this depth
                ans.push_back(d-1);  
            } 
            else {
                if(myH == max1)
                    ans.push_back(d + max2);
                else
                    ans.push_back(d + max1);
            }
        }

        return ans;
    }
}; 