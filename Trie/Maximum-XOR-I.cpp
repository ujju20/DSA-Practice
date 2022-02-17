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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto x:nums)
        {
            trie.insert(x);
        }
        int ans=0;
        for(auto x:nums)
        {
            ans=max(ans,trie.getMax(x));
        }
        return ans;
    }
};
