class Solution {
public:
    string res;
    string getHappyString(int n, int k) {
        string temp="";
        backtrack(n,k,temp);
        return res;
    }
    void backtrack(int &n,int &k,string temp)
    {
        if(temp.size()==n)
        {
            k--;
            if(k==0) res=temp;
            return;
        }
        if(temp.back()!='a') backtrack(n,k,temp+'a');
        if(temp.back()!='b') backtrack(n,k,temp+'b');
        if(temp.back()!='c') backtrack(n,k,temp+'c');
    }
};