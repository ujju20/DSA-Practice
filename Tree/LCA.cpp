/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node==NULL or node==p or node==q)
            return node;
        TreeNode* left=lca(node->left,p,q);
        TreeNode* right=lca(node->right,p,q);
        
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};
