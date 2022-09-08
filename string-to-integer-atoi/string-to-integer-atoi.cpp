class Solution {
public:
    int myAtoi(string s) {
        int i=0,sign=1,res=0;
        if(s.size()==0) return res;
        while(i<s.size() and s[i]==' ') i++;
        if(i<s.size() and (s[i]=='+' or s[i]=='-')) sign=(s[i++]=='-'?-1:1);
        while(i<s.size() and s[i]>='0' and s[i]<='9')
        {
            if(res>INT_MAX/10 or (res==INT_MAX/10 and s[i]-'0'>INT_MAX%10)) 
                return (sign==1?INT_MAX:INT_MIN);
            res=res*10+(s[i++]-'0');
        }
        return res*sign;
    }
};