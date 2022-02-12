class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> s;
        bool present=false;
        for(string w:word)
        {
            if(w==end) present=true;
            s.insert(w);
        }
        if(present==false) return 0;
        queue<string> q;
        q.push(begin);
        int depth=0;
        while(!q.empty())
        {
            depth++;
            int size=q.size();
            while(size--)
            {
                string cur=q.front();
                q.pop();
                for(int i=0;i<cur.size();i++)
                {
                    string temp=cur;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(cur==temp) continue; //skip same word
                        if(temp==end) return depth+1;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};