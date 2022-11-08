class Solution {
public:
    string makeGood(string s) {
        int end=0;
        for(int cur=0;cur<s.size();cur++)
        {
            if(end>0 and abs(s[cur]-s[end-1]) ==32)
                end--;
            else
            {
                s[end]=s[cur];
                end++;
            }
        }
        string res=s.substr(0,end);
        return res;
    }
};