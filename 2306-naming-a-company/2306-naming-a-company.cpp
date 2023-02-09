class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> initialGroup[26];
        for(auto idea:ideas)
            initialGroup[idea[0]-'a'].insert(idea.substr(1));
        long long res=0;
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int mutual=0;
                for(auto a:initialGroup[i])
                {
                    if(initialGroup[j].count(a)) mutual++;
                }
                res+=2LL*(initialGroup[i].size()-mutual)*(initialGroup[j].size()-mutual);
            }
        }
        return res;
    }
};