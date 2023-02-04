class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char ch:s1) mp[ch]++;
        int start=0,match=0;
        for(int end=0;end<s2.size();end++)
        {
            char right=s2[end];
            if(mp.count(right))
            {
                mp[right]--;
                if(mp[right]==0) match++;
            }
            if(match==(int)mp.size()) return true;
            if(end>=s1.size()-1)
            {
                char left=s2[start];
                if(mp.count(left))
                {
                    if(mp[left]==0) match--;
                    mp[left]++;
                }
                start++;
            }
        }
        return false;
    }
};