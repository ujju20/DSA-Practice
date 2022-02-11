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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            if(node==NULL)
                s.push_back('#');
            else
            {
                s.append(to_string(node->val));
            }
            s.push_back(',');
            if(node!=NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;

        stringstream s(data);
        //cout<<data<<" ";
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            
            getline(s,str,',');
            //cout<<str<<" ";
            if(str=="#")
                node->left=NULL;
            else
            {
                TreeNode* n=new TreeNode(stoi(str));
                node->left=n;
                q.push(n);
            }
            getline(s,str,',');
            //cout<<str<<" ";
            if(str=="#")
                node->right=NULL;
            else
            {
                TreeNode* n=new TreeNode(stoi(str));
                node->right=n;
                q.push(n);
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
