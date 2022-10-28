class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs)
        {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> ana;
        for(auto a:mp)
            ana.push_back(a.second);
        return ana;
    }
    private:
    string strSort(string s)
    {
        int count[26]={0};
        for(char c:s)
            count[c-'a']++;
        string str;
        for(int i=0;i<26;i++)
            str+=string(count[i],i+'a');
        return str;
    }
};