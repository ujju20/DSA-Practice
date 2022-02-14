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
    TreeNode* buildTree(vector<int> preorder,int &i,int bound)
    {
        if(i==preorder.size() or preorder[i]>bound) return NULL;
        
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=buildTree(preorder,i,node->val);
        node->right=buildTree(preorder,i,bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildTree(preorder,i,INT_MAX);
    }
};
