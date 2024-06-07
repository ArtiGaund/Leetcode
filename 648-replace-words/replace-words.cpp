class TrieNode{
    public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): children(26,nullptr){ isEnd=false; }
};
class Trie{
    private: TrieNode *root;
    public: 
    Trie(){
        root=new TrieNode();
    }
    void insert(string word){
        TrieNode *cur=root;
        for(char ch:word){
            if(cur->children[ch-'a']==nullptr)
                cur->children[ch-'a']=new TrieNode();
            cur=cur->children[ch-'a'];
        }
        cur->isEnd=true;
    }
    string shortestRoute(string word){
        TrieNode *cur=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(cur->children[ch-'a']==nullptr){
                return word;
            }
            cur=cur->children[ch-'a'];
            if(cur->isEnd){
                return word.substr(0,i+1);
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        Trie dict;
        for(string word:dictionary) dict.insert(word);
        string word;
        string newSentence;
        while(getline(sStream,word,' ')){
            newSentence+=dict.shortestRoute(word)+" ";
        }
        newSentence.pop_back();
        return newSentence;
    }
};