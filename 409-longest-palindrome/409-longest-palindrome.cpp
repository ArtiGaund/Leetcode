class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        int odd=0,max_len=0;
        for(auto it:mp)
        {
            if(it.second%2==0) max_len+=it.second;
            else
            {
                max_len+=it.second-1;
                odd=1;
            }
        }
        return max_len+odd;
    }
};