class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(char c:s1) mp[c]++;
        int start=0,end=0;
        int count=mp.size();
        while(end<s2.size())
        {
            char ch=s2[end];
            if(mp.count(ch))
            {
                mp[ch]--;
                if(mp[ch]==0) count--;
            }
            end++;
            while(count==0)
            {
                char temp=s2[start];
                if(mp.count(temp))
                {
                    mp[temp]++;
                    if(mp[temp]>0) count++;
                }
                if(end-start==s1.size()) return true;
                start++;
            }
        }
        return false;
    }
};