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
class BSTIterator {
    stack<TreeNode*> s;
    bool isReverse=true;
public:
    BSTIterator(TreeNode* root,bool reverse) {
        this->isReverse=reverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        if(isReverse==true)
            pushAll(node->left);
        else
            pushAll(node->right);
        return node->val;
    }
    private:
    void pushAll(TreeNode* node)
    {
        if(isReverse==true)
           for(;node!=NULL;s.push(node),node=node->right);
        else
            for(;node!=NULL;s.push(node),node=node->left);
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            //cout<<i<<" "<<j<<endl;
            if(i+j==k)
                return true;
            else if(i+j>k)
                j=r.next();
            else
                i=l.next();
        }
       // cout<<endl;
        return false;
        
    }
};
