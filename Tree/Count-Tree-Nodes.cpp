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

// O((Log^2N)) Solution

class Solution {
    int count(TreeNode* root)
{
    if(root==NULL)
        return 0;
    
    int lh=findHeight(root,'L');
    int rh=findHeight(root,'R');
    if(lh==rh) return (1<<lh)-1;
    
    return 1+count(root->left)+count(root->right);
}
int findHeight(TreeNode* node,char check)
{
    int high=0;
    if(check=='L')
    {
        while(node)
        {
            high++;
            node=node->left;
        }
    }
    else
    {
        while(node)
        {
            high++;
            node=node->right;
        }
    }
    return high;
}
public:
    int countNodes(TreeNode* root) {
        return count(root);
    }
};
