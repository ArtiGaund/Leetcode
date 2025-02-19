class Solution {
public:
    string getHappyString(int n, int k) {
        int total=3*(1<<(n-1));
        if(k>total) return "";
        string res(n,'a');
        unordered_map<char,char> nextSmallest={
            {'a','b'}, {'b','a'},{'c','a'}
        };
        unordered_map<char,char> nextGreatest={
            {'a','c'},{'b','c'},{'c','b'}
        };
        int startA=1;
        int startB=startA+(1<<(n-1));
        int startC=startB+(1<<(n-1));
        if(k<startB){
            res[0]='a';
            k-=startA;
        }else if(k<startC){
            res[0]='b';
            k-=startB;
        }else{
            res[0]='c';
            k-=startC;
        }
        for(int i=1;i<n;i++){
            int midpoint=(1<<(n-i-1));
            if(k<midpoint) res[i]=nextSmallest[res[i-1]];
            else{
                res[i]=nextGreatest[res[i-1]];
                k-=midpoint;
            }
        }
        return res;
    }
};