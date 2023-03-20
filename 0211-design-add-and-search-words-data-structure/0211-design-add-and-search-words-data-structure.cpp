class Node
{
    public: bool isEnd;
            Node *children[26];
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *cur=root;
        for(int i=0;i<word.size();i++)
        {
            if(cur->children[word[i]-'a']==nullptr)
                cur->children[word[i]-'a']=new Node();
            cur=cur->children[word[i]-'a'];
        }
        cur->isEnd=true;
    }
    
    bool searchWord(Node* temp, string &word, int i)
    {
        if(i == word.length())
            return (temp->isEnd) ? 1 : 0;
        bool ans=0;   
        if(word[i] != '.')
        {
            if(!(temp->children[word[i] - 'a']))
                return false;
            return searchWord(temp->children[word[i] - 'a'], word, i+1);
        }
        else if(word[i] == '.')
        {
            for(int j=0;j<26;j++)
            {
                if(temp->children[j])
                    ans = ans || searchWord(temp->children[j], word, i+1);
            }
        }
        return ans;
    }    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
   
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */