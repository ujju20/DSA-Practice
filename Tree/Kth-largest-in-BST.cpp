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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr=root->left;
        int ans=-1;
        while(curr!=NULL or !s.empty())
        {
            if(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* node=s.top();
                s.pop();
                cnt++;
                //cout<<cnt;
                if(cnt==k)
                    return node->val;
                curr=node->right;
            }
        }
        return -1;
    }
};
