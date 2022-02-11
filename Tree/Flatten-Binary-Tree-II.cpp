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

//Moris Travel O(1) Space
class Solution {
    //TreeNode* prev=NULL;
public:
    void flatten(TreeNode* root) {
       TreeNode* curr=root;
        while(curr)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev=curr->left;
                while(prev->right)
                    prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }
};
