class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n%2) return false;
        int unlock=0,open=0,close=0,unpaired=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0') unlock++;
            else if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            unpaired=open-close;
            if(unpaired>unlock) return false;
        }
        unlock=0;
        open=0;
        close=0;
        unpaired=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0') unlock++;
            else if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            unpaired=close-open;
            if(unpaired>unlock) return false;
        }
        return true;
    }
};