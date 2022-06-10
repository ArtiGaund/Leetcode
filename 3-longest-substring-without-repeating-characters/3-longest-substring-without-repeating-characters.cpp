class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        vector<int> count(128,0);
        int start=0,end=0;
        int maxlen=INT_MIN;
        while(end<s.size())
        {
            char right=s[end];
            count[right]++;
            while(count[right]>1)
            {
                char left=s[start];
                count[left]--;
                start++;
            }
            maxlen=max(maxlen,end-start+1);
            end++;
        }
        return maxlen;
    }
};