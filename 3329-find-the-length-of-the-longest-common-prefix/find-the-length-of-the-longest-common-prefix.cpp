class TrieNode{
    public:
    TrieNode *children[10];
    TrieNode(){
        for(int i=0;i<10;i++)
            children[i]=nullptr;
    }
};
class Trie{
    public: 
    TrieNode *root;
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode *node=root;
        string str=to_string(num);
        for(char ch:str){
            int index=ch-'0';
            if(!node->children[index])
                node->children[index]=new TrieNode();
            node=node->children[index];
        }
    }
    int findLongestPrefix(int num){
        TrieNode *node=root;
        string str=to_string(num);
        int len=0;
        for(char ch:str){
            int index=ch-'0';
            if(node->children[index]){
                len++;
                node=node->children[index];
            }else break;
        }
        return len;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int arr:arr1) trie.insert(arr);
        int res=0;
        for(int arr:arr2){
            int len=trie.findLongestPrefix(arr);
            res=max(res,len);
        }
        return res;
    }
};