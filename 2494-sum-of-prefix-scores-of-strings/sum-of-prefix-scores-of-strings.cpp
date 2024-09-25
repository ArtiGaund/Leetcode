struct TrieNode{
    TrieNode *next[26]={};
    int cnt=0;
};
class Solution {
public:
    TrieNode root;
    void insert(string word){
        auto node=&root;
        for(char ch:word){
            if(!node->next[ch-'a'])
                node->next[ch-'a']=new TrieNode();
            node->next[ch-'a']->cnt++;
            node=node->next[ch-'a'];
        }
    }
    int count(string s){
        auto node=&root;
        int res=0;
        for(char ch:s){
            res+=node->next[ch-'a']->cnt;
            node=node->next[ch-'a'];
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
            insert(words[i]);
        vector<int> scores(n,0);
        for(int i=0;i<n;i++)
            scores[i]=count(words[i]);
        return scores;
    }
};