class Solution {
    unordered_map<string,int> mp;
    string b;
    vector<vector<string>> res;
public:
    void dfs(string word,vector<string> &seq)
    {
        if(word==b)
        {
            reverse(seq.begin(),seq.end());
            res.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mp[word];
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(mp.find(word)!=mp.end() and mp[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }
    vector<vector<string>> findLadders(string begin, string end, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(begin);
        b=begin;
        mp[begin]=1;
        int size=begin.size();
        st.erase(begin);
        if(st.find(end)==st.end()) return {};
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            int steps=mp[word];
            if(word==end) break;
            for(int i=0;i<size;i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        if(mp.find(end)!=mp.end())
        {
            vector<string> seq;
            seq.push_back(end);
            dfs(end,seq);
        }
        return res;
    }
};