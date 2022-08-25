class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ran[26]={0},mag[26]={0};
        for(int i=0;i<ransomNote.size();i++)
            ran[ransomNote[i]-'a']+=1;
        for(int i=0;i<magazine.size();i++)
            mag[magazine[i]-'a']+=1;
        for(int i=0;i<26;i++)
        {
            if(mag[i]<ran[i])
                return false;
        }
        return true;
    }
};