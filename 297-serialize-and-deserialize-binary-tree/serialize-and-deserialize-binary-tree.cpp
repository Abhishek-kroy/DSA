/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string getans(TreeNode* root){
        if(!root){
            return "NULL,";
        }

        string ans=to_string(root->val)+",";

        ans+=getans(root->left);
        ans+=getans(root->right);

        return ans; 
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string ans=getans(root);

        cout<<ans<<endl; 

        return ans;
    }    

    TreeNode* getdat(string& data,int& i)    {
        if(i>=(int)(data.size())){
            return NULL;
        }

        int n=data.size();

        string val="";

        while(i<n && data[i]!=','){          
            val+=data[i];
            i++;                                    
        }

        i++;

        if(val=="NULL"){
            return NULL;
        }

        TreeNode* r=new TreeNode(stoi(val));

        r->left=getdat(data,i);
        r->right=getdat(data,i);

        return r;                
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;

        return getdat(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));