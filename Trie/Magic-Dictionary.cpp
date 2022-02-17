// Link to Question - https://leetcode.com/problems/implement-magic-dictionary/
class Node{
     public:
    Node* links[26];
    bool flag=false;
   
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
class MagicDictionary {
    Node* root;
public:
    MagicDictionary() {
        root=new Node();
    }
    
    void buildDict(vector<string> d) {
       
        for(auto s:d)
        {
            Node* node=root;
            for(int i=0;i<s.length();i++)
            {
                if(!node->containsKey(s[i]))
                {
                    node->put(s[i],new Node());
                }
                node=node->get(s[i]);
            }
            node->makeEnd();
        }
    }
    bool helper(Node* node,string s,int i,int cnt)
    {
        if(cnt>1)
            return false;
        if(i==s.size())
        {
            if(node->isEnd() and cnt==1)
                return true;
            return false;
        }
        for(int k=0;k<26;k++)
        {
            if(node->links[k]==NULL)
                continue;
            else if(helper(node->links[k],s,i+1,k==s[i]-'a'?cnt:cnt+1))
                return true;
        }
        return false;
    }
    bool search(string word) {
        Node *node=root;
       return helper(node,word,0,0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
