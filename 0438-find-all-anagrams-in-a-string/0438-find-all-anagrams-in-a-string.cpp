class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        for(char ch:p) mp[ch]++;
        vector<int> res;
        int start=0,match=0;
        for(int end=0;end<s.size();end++)
        {
            char right=s[end];
            if(mp.count(right))
            {
                mp[right]--;
                if(mp[right]==0) match++;
            }
            if(match==(int)mp.size()) res.push_back(start);
            if(end>=p.size()-1)
            {
                char left=s[start];
                if(mp.count(left))
                {
                    if(mp[left]==0) match--;
                    mp[left]++;
                }
                start++;
            }
        }
        return res;
    }
};