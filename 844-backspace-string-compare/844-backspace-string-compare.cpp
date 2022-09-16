class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int index1=s.size()-1,index2=t.size()-1;
        while(index1>=0 or index2>=0)
        {
            int a=getNextValidChar(s,index1);
            int b=getNextValidChar(t,index2);
            if(a<0 and b<0) return true;
            if(a<0 or b<0) return false;
            if(s[a]!=t[b]) return false;
            index1=a-1;
            index2=b-1;
        }
        return true;
    }
    int getNextValidChar(string &s,int index)
    {
        int backspace=0;
        while(index>=0)
        {
            if(s[index]=='#') backspace++;
            else if(backspace>0) backspace--;
            else break;
            index--;
        }
        return index;
    }
};