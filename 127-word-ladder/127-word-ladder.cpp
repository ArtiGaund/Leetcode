class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({begin,0});
        unordered_set<string> vis;
        vis.insert(begin);
        int ans=INT_MAX;
        while(!q.empty())
        {
            auto cur=q.front();
            q.pop();
            string str=cur.first;
            int wt=cur.second;
            if(str==end)
            {
                ans=min(ans,wt);
                break;
            }
            for(int i=0;i<str.size();i++)
            {
                char c=str[i];
                for(char j='a';j<='z';j++)
                {
                    if(c!=j)
                    {
                        str[i]=j;
                        if(s.find(str)!=s.end() and vis.count(str)==0)
                        {
                            q.push({str,wt+1});
                            vis.insert(str);
                        }
                    }
                }
                str[i]=c;
            }
        }
        return (ans==INT_MAX?0:ans+1);
    }
};