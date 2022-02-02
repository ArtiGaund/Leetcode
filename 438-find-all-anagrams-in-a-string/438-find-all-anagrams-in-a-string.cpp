class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size()) return {};
        unordered_map<char,int> mp;
        for(char c:p) mp[c]++;
        int count=mp.size();
        int start=0,end=0;
        vector<int> res;
        while(end<s.size())
        {
            char ch=s[end];
            if(mp.count(ch))
            {
                mp[ch]--;
                if(mp[ch]==0) count--;
            }
            end++;
            while(count==0)
            {
                char temp=s[start];
                if(mp.count(temp))
                {
                    mp[temp]++;
                    if(mp[temp]>0) count++;
                }
                if(end-start==p.size()) res.push_back(start);
                start++;
            }
        }
        return res;
    }
};