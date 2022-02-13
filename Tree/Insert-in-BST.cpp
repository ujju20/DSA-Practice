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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* node=new TreeNode(val);
            return node;
        }
        TreeNode* curr=root;
        while(true)
        {
           if(root->val<val)
           {
               if(root->right!=NULL)
                   root=root->right;
               else
               {
                   TreeNode* node=new TreeNode(val);
                   root->right=node;
                   break;
               }
           }
            else
            {
                if(root->left!=NULL)
                   root=root->left;
               else
               {
                   TreeNode* node=new TreeNode(val);
                   root->left=node;
                   break;
               }
            }
        }
        return curr;
    }
};
