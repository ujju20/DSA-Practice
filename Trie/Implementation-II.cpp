class Node{
    Node* links[26];
    int cp=0;
    int ew=0;
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
    void increaseEnd()
    {
        ew++;
    }
    void increaseprefix()
    {
        cp++;
    }
    int countEnd()
    {
        return ew;
    }
    int countPrefix()
    {
        return cp;
    }
    void deleteEnd()
    {
        ew--;
    }
    void deletePrefix()
    {
        cp--;
    }
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->countEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->countPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                node->deletePrefix();
                
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};
