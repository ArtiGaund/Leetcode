#define SIZE 26
class trie_node
{
    public:
    bool isLeaf;
    trie_node *children[SIZE];
    trie_node(bool leaf)
    {
        isLeaf=leaf;
        for(int i=0;i<SIZE;i++)
            children[i]=nullptr;
    }
};
class Trie {
public:
    trie_node *root=nullptr;
    Trie() {
        root=new trie_node(false);
    }
    
    void insert(string word) {
        trie_node *cur=root;
        for(char ch:word)
        {
            if(cur->children[ch-'a']==nullptr)
                cur->children[ch-'a']=new trie_node(false);
            cur=cur->children[ch-'a'];
        }
        cur->isLeaf=true;
    }
    
    bool search(string word) {
        trie_node *cur=root;
        for(char ch:word)
        {
            if(cur==nullptr) break;
            cur=cur->children[ch-'a'];
        }
        return (cur!=nullptr and cur->isLeaf==true);
    }
    
    bool startsWith(string prefix) {
        trie_node *cur=root;
        for(char ch:prefix)
        {
            if(cur==nullptr) break;
            cur=cur->children[ch-'a'];
        }
        return (cur!=nullptr);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */