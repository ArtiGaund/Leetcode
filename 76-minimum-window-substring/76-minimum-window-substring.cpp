class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:t) mp[ch]++;
        int start=0,matched=0,minlen=s.size()+1,substart=0;
        for(int end=0;end<s.size();end++)
        {
            char right=s[end];
            if(mp.find(right)!=mp.end())
            {
                mp[right]--;
                if(mp[right]>=0) matched++;
            }
            while(matched==t.size())
            {
                if(minlen>end-start+1)
                {
                    minlen=end-start+1;
                    substart=start;
                }
                char left=s[start++];
                if(mp.find(left)!=mp.end())
                {
                    if(mp[left]==0) matched--;
                    mp[left]++;
                }
            }
        }
        return minlen>s.size()?"":s.substr(substart,minlen);
    }
};