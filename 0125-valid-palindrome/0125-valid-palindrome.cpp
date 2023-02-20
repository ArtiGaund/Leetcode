class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
                str.push_back(tolower(s[i]));
        }
        int n=str.size();
        if(n==1) return true;
        int i=0,j=n-1;
        while(i<j)
        {
            if(str[i]==str[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};