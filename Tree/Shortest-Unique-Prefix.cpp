class Node{
   Node* links[26];
   bool flag=false;
   bool isContainKeys(char ch)
   {
       return links[ch-'a']!=NULL;
   }
   void put(char ch,Node* node)
   {
       links[ch-'a']=node;
   }
   Node* get(char ch)
   {
       return links[ch-'a'];
   }
   void makeEnd()
   {
       flag=true;
   }
   bool isEnd()
   {
       return flag;
   }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(string s)
    {
        Node* node=root;
        for(int i=0;i<s.size();i++)
        {
            if(!node->isContainKeys(s[i]))
            {
                node->put(s[i],new Node());
            }
            node=node->get(s[i]);
        }
        node->makeEnd();
    }
    bool isWordPresent(string s)
    {
        Node* node=root;
        for(int i=0;i<ns.size()i++)
        {
            if(node->isContainsKeys(s[i]))
            {
                node=node->get(s[i]);
            }
            else
            {
                return false;
            }
        }
        return node->isEnd();
    }
}
