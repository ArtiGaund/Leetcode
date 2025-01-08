class Node{
    public:
    Node *links[26]={};
    bool contains(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *next(char ch){
        return links[ch-'a'];
    }
};
class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node *node=root;
        for(char ch:word){
            if(!node->contains(ch)){
                node->put(ch,new Node());
            }
            node=node->next(ch);
        }
    }
    bool startsWith(string &prefix){
        Node *node=root;
        for(char ch:prefix){
            if(!node->contains(ch)){
                return false;
            }
            node=node->next(ch);
        }
        return true;
    }

};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            Trie prefixTrie,suffixTrie;
            prefixTrie.insert(words[i]);
            string revWord=words[i];
            reverse(revWord.begin(),revWord.end());
            suffixTrie.insert(revWord);
            for(int j=0;j<i;j++){
                if(words[j].size()>words[i].size()) continue;
                string prefixWord=words[j];
                string revPrefixWord=prefixWord;
                reverse(revPrefixWord.begin(),revPrefixWord.end());
                if(prefixTrie.startsWith(prefixWord) and suffixTrie.startsWith(revPrefixWord)) count++; 
            }
        }
        return count;
    }
};