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

//Root Left Right
class Solution {
    void rec(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        rec(root->left,ans);
        rec(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //rec(root,ans);
        if(root==NULL)
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL)
                st.push(node->right);
            if(node->left!=NULL)
                st.push(node->left);
        }
        return ans;
    }
};
