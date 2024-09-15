class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        int charMp[26]={0};
        charMp['a'-'a']=1;
        charMp['e'-'a']=2;
        charMp['i'-'a']=4;
        charMp['o'-'a']=8;
        charMp['u'-'a']=16;
        vector<int> mp(32,-1);
        int longest=0;
        for(int i=0;i<s.size();i++){
            prefixXOR^=charMp[s[i]-'a'];
            if(mp[prefixXOR]==-1 and prefixXOR!=0) mp[prefixXOR]=i;
            longest=max(longest,i-mp[prefixXOR]);
        }
        return longest;
    }
};