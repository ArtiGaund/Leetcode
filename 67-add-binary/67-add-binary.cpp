class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int s=0;
        int i=a.size()-1,j=b.size()-1;
        while(i>=0||j>=0||s==1)
        {
            s+=(i>=0?a[i]-'0':0);
            s+=(j>=0?b[j]-'0':0);
            res=char(s%2+'0')+res;
            s/=2;
            i--;
            j--;
        }
        return res;
    }
};