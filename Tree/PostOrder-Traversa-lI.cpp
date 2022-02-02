lass Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> s1;
        vector<int> ans;
        Node* curr=node->left;
        s1.push(node);
        while(curr!=NULL or !s1.empty())
        {
            if(curr!=NULL)
            {
                s1.push(curr);
                curr=curr->left;
            }
            else
            {
                Node *temp=s1.top();
                //s1.pop();
                if(temp->right==NULL)
                {
                    s1.pop();
                    ans.push_back(temp->data);
                    while(!s1.empty() and temp==s1.top()->right)
                    {
                        ans.push_back(s1.top()->data);
                        temp=s1.top();
                        s1.pop();
                        
                    }
                }
                else
                {
                    curr=temp->right;
                }
            }
        }
        return ans;
    }
};
