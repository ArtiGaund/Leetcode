class Solution {
public:
    struct trie
    {
        bool end;
        trie *child[26];
    };
    void insert(trie *root,string word)
    {
        trie *cur=root;
        for(char ch:word)
        {
            int index=ch-'a';
            if(cur->child[index]==nullptr)
                cur->child[index]=new trie();
            cur=cur->child[index];
        }
        cur->end=true;
    }
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        trie *root=new trie();
        for(string s:words) insert(root,s);
        string s;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++)
                dfs(i,j,board,root,s);
        return res;
    }
    void dfs(int i,int j,vector<vector<char>> &b,trie *root,string &word)
    {
        if(!(i>=0 and i<b.size() and j>=0 and j<b[0].size() and b[i][j]!=' ')) return;
        char ch=b[i][j];
        if(root->child[ch-'a']==nullptr) return;
        root=root->child[ch-'a'];
        word.push_back(ch);
        if(root->end)
        {
            res.push_back(word);
            root->end=false;
        }
        b[i][j]=' ';
        dfs(i+1,j,b,root,word);
        dfs(i-1,j,b,root,word);
        dfs(i,j+1,b,root,word);
        dfs(i,j-1,b,root,word);
        b[i][j]=ch;
        word.pop_back();
    }
};