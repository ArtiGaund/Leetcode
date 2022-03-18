class Solution {
public:
    string removeDuplicateLetters(string s) {
       string res;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        if(res.size()==mp.size())
            return res;
        for(int i=0;i<s.size();i++)
        {
            while(res.size()>0&&res.back()>s[i]&&mp[res.back()]>0&&res.find(s[i])==-1)
                res.pop_back();
            if(res.find(s[i])==-1)
                res.push_back(s[i]);
            mp[s[i]]--;
        }
        return res;
    }
};