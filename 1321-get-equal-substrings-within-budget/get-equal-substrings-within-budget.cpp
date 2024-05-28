class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=abs(s[i]-t[i]);
        int max_len=0;
        int start=0,sum=0;
        for(int end=0;end<n;end++)
        {
            sum+=v[end];
            while(sum>maxCost)
            {
                sum-=v[start];
                start++;
            }
            max_len=max(max_len,end-start+1);
        }
        return max_len;
    }
};