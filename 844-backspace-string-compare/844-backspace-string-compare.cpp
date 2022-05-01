class Solution {
public:
    bool backspaceCompare(string S, string T) {
         deque<char> q1,q2;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='#')
                q1.push_back(S[i]);
            else if(!q1.empty())
                q1.pop_back();
        }
        for(int i=0;i<T.size();i++)
        {
            if(T[i]!='#')
                q2.push_back(T[i]);
            else if(!q2.empty())
                q2.pop_back();
        }
        string s1="",s2="";
        while(!q1.empty())
        {
            s1+=q1.front();
            q1.pop_front();
        }
        while(!q2.empty())
        {
            s2+=q2.front();
            q2.pop_front();
        }
        if(s1==s2)
            return true;
        else
            return false;
    }
};