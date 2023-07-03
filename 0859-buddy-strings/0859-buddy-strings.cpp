class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal)
        {
            vector<int> freq(26,0);
            for(auto ch:s)
            {
                freq[ch-'a']+=1;
                if(freq[ch-'a']==2) return true;
            }
        }
        int first=-1,sec=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                if(first==-1) first=i;
                else if(sec==-1) sec=i;
                else return false;
            }
        }
        if(sec==-1) return false;
        return (s[first]==goal[sec] and s[sec]==goal[first]);
    }
};