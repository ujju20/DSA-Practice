//https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1
class Node{
    Node* links[26];
    bool flag=false;
    public:
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    bool isEnd()
    {
        return flag;
    }
    void makeEnd()
    {
        flag=true;
    }
};
class Trie{
    private: Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->makeEnd();
    }
    bool checkWithPrefixes(string word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
           if(node->containsKey(word[i]))
           {
               node=node->get(word[i]);
               if(node->isEnd()==false)
                   return false;
           }
            else
            {
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(int i=0;i<n;i++)
    {
        trie.insert(a[i]);
    }
    string longest="";
    for(int i=0;i<a.size();i++)
    {
        if(trie.checkWithPrefixes(a[i]))
        {
            if(a[i].size()>longest.size())
            {
                longest=a[i];
            }
            else if(longest.size()==a[i].size() and a[i]<longest)
            {
                longest=a[i];
            }
        }
    }
    if(longest=="")
        return "None";
    return longest;
}
