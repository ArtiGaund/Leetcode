class Solution {
public:
    int expand(string s,int left,int right){
        if(s.size()==0 or left>right) return 0;
        while(left>=0 and right<s.size() and s[left]==s[right])
        {
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return "";
        int start=0,end=0;
        for(int i=0;i<n;i++)
        {
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start)
            {
                start=i-((len-1)/2);
                end=i+(len/2);
            }
        }
        return s.substr(start,end-start+1);
    }
};