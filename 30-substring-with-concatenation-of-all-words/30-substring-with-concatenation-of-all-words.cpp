class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mp;
        for(string str:words) mp[str]++;
        int len=words[0].size(),count=words.size();
        vector<int> res;
        int l=0,r=0;
        for(int start=0;start<len;start++)
        {
            unordered_map<string,int> cur_mp;
            int cur_count=0;
            l=start;
            for(r=start;r+len-1<s.size();r+=len)
            {
                string word=s.substr(r,len);
                if(mp.find(word)!=mp.end())
                {
                    if(++cur_mp[word]<=mp[word]) ++cur_count;
                    while(cur_mp[word]>mp[word])
                    {
                        string temp=s.substr(l,len);
                        if(--cur_mp[temp]<mp[temp]) --cur_count;
                        l+=len;
                    }
                    if(cur_count==count) res.push_back(l);
                }
                else
                {
                    cur_mp.clear();
                    cur_count=0;
                    l=r+len;
                }
                    
            }
        }
        return res;
    }
};