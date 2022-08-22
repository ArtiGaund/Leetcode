class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==0) return 0;
        int start=0,maxlen=0,maxRepeat=0;
        unordered_map<char,int> mp;
        for(int end=0;end<n;end++)
        {
            char right=s[end];
            mp[right]++;
            maxRepeat=max(maxRepeat,mp[right]);
            if(end-start+1-maxRepeat>k)
            {
                char left=s[start];
                mp[left]--;
                if(mp[left]==0) mp.erase(left);
                start++;
            }
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
    }
};