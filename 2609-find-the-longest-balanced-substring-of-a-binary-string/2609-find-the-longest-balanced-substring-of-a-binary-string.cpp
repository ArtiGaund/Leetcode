class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int maxlen=0;
        for(int i=0;i<s.size();)
        {
            int ones=0,zeros=0;
            while(i<s.size() and s[i]=='0')
            {
                zeros++;
                i++;
            }
            while(i<s.size() and s[i]=='1')
            {
                ones++;
                i++;
            }
            int len=2*min(ones,zeros);
            maxlen=max(maxlen,len);
        }
        
        return maxlen;
    }
};