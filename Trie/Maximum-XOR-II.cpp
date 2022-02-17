class Node{
   Node* links[2];
    public:
   bool containsKey(int bit)
   {
       return links[bit]!=NULL;
   }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node* node)
    {
        links[bit]=node;
    }
};
class Trie{
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node* node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
               node=node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node* node=root;
        int maxAns=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->containsKey(!bit))
            {
                maxAns=maxAns | (1<<i);
                node=node->get(!bit);
            }
            else
                node=node->get(bit);
            
        }
        return maxAns;
    }
    
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        vector<vector<int> >oQ;
        int q=queries.size();
        vector<int> ans(q,0);
        for(int i=0;i<queries.size();i++)
        {
            oQ.push_back({queries[i][1],queries[i][0],i});
        }
        sort(oQ.begin(),oQ.end());
        int ind=0;
        for(int i=0;i<q;i++)
        {
            int ai=oQ[i][0];
            int xi=oQ[i][1];
            int idx=oQ[i][2];
            
            while(ind<nums.size() and nums[ind]<=ai)
            {
                trie.insert(nums[ind]);
                ind++;
            }
            
            if(ind==0)
            {
                ans[idx]=-1;
            }
            else
            {
                ans[idx]=trie.getMax(xi);
            }
        }
  
        return ans;
    }
};
