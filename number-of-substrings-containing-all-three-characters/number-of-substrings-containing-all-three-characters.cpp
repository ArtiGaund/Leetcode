class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> count={0,0,0};
        int start=0,res=0,c=0;
        for(int end=0;end<n;end++)
        {
            count[s[end]-'a']++;
            while(start<n and count[0] and count[1] and count[2])
            {
                c++;
                count[s[start]-'a']--;
                start++;
            }
            res+=c;
        }
        return res;
    }
};