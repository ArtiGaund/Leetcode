class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(s.size()<k or k>26) return 0;
       vector<int> freq(26,0);
        int res=0;
        int start=0,end=0;
        while(end<s.size())
        {
            freq[s[end]-'a']++;
            while(freq[s[end]-'a']>1)
            {
                freq[s[start]-'a']--;
                start++;
            }
            if(end-start+1==k) 
            {
                res++;
                freq[s[start]-'a']--;
                start++;
            }
            end++;
            
        }
        return res;
    }
};