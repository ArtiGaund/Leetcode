class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26,0);
        for(auto a:magazine) count[a-'a']++;
        for(int i=0;i<ransomNote.size();i++)
        {
            if(count[ransomNote[i]-'a']>0) count[ransomNote[i]-'a']--;
            else if(count[ransomNote[i]-'a']==0) return false;
        }
        return true;
    }
};