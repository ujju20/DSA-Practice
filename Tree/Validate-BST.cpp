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
    bool rec(TreeNode* root,long long int min_val,long long int max_val)
    {
        if(!root)
            return true;
        
        if(root->val>=max_val or root->val<=min_val) return false;
        
        return rec(root->left,min_val,root->val) and rec(root->right,root->val,max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root or (!root->left and !root->right))
            return true;
        //long long int min_val=INT_MIN-1,max_val=INT_MAX+1;
        return rec(root,LONG_MIN,LONG_MAX);
    }
};
