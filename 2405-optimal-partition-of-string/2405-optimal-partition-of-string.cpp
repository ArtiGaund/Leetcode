class Solution {
public:
    int partitionString(string s) {
        vector<int> seen(26,-1);
        int count=1,substringstart=0;
        for(int i=0;i<s.size();i++)
        {
            if(seen[s[i]-'a']>=substringstart)
            {
                count++;
                substringstart=i;
            }
            seen[s[i]-'a']=i;
        }
        return count;
    }
};