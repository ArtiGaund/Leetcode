class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> set;
        bool present=false;
        for(string s:wordList)
        {
            if(s==end) present=true;
            set.insert(s);
        }
        if(!present) return 0;
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
                for(int pos=0;pos<cur.size();pos++)
                {
                    string temp=cur;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[pos]=ch;
                        if(temp==cur) continue;
                        if(temp==end) return depth+1;
                        else if(set.find(temp)!=set.end())
                        {
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};