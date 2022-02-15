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
    TreeNode* prev,*first,*middle,*last;
    void recover(TreeNode* root)
    {
        if(!root)
            return;
        
        recover(root->left);
        if(prev!=NULL and root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                middle=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        recover(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=last=middle=NULL;
        prev=new TreeNode(INT_MIN);
        recover(root);
        if(first and last) swap(first->val,last->val);
        else if(first and middle) swap(first->val,middle->val);
        return;
    }
};
