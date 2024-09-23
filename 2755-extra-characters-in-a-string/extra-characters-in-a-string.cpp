class TrieNode{
    public:
    unordered_map<char,TrieNode*> children;
    bool is_word;
};
class Solution {
public:
    TrieNode *buildTrie(vector<string> &dict){
        auto root=new TrieNode();
        for(auto w:dict){
            auto node=root;
            for(auto ch:w){
                if(node->children.find(ch)==node->children.end())
                    node->children[ch]=new TrieNode();
                node=node->children[ch];
            }
            node->is_word=true;
        }
        return root;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        auto root=buildTrie(dict);
        vector<int> dp(n+1,0);
        for(int start=n-1;start>=0;start--){
            dp[start]=dp[start+1]+1;
            auto node=root;
            for(int end=start;end<n;end++){
                if(node->children.find(s[end])==node->children.end()) break;
                node=node->children[s[end]];
                if(node->is_word) dp[start]=min(dp[start],dp[end+1]);
            }
        }
        return dp[0];
    }
};