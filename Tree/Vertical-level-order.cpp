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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int> > > m;
        queue<pair<TreeNode*,pair<int,int> > >q;
        vector<vector<int> >ans;
        q.push({root,{0,0}});
       // m[0][0].insert(root->val);
        while(!q.empty())
        {
            auto pa=q.front();
            q.pop();
            TreeNode* node=pa.first;
            auto p=pa.second;
            if(node->left)
                q.push({node->left,{p.first-1,p.second+1}});
            if(node->right)
                q.push({node->right,{p.first+1,p.second+1}});
            m[p.first][p.second].insert(node->val);
        }
        
        for(auto x:m)
        {
            vector<int> col;
            for(auto y:x.second)
            {
                col.insert(col.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
        
    }
};
